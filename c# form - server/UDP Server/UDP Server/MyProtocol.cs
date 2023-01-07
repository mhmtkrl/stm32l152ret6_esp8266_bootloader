﻿using Cave;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UDP_Server;

namespace UDP_Server
{
    internal class MyProtocol
    {
        byte CMD = 0x01;
        byte COUNTER = 0x00;
        byte FRAME_TYPE = 0xCD;

        Form1 form1;
        UDP_Communication communication = new UDP_Communication();

        public void protocol_update(Form1 newForm1)
        {
            form1 = newForm1;
            communication.communication_update2(this);
        }
        
        public void Protocol_Init()
        {
            
            communication.communication_update2(this);
            communication.StartProcess();
            
        }

        public void showMsg(string pkt)
        {
            form1.listBox1.Items.Add(pkt);

        }

        private byte Crc_Calculate(byte[] data)
        {
            byte Checksum = 0x00;
            /* CRC32 calculation - nuget */
            CRC32 crc32a = CRC32.MPEG2;
            
            crc32a.Reset();
            crc32a.Update(data);

            uint result = crc32a.Value;

            /* Calculate checksum value of the calculated 32-bit CRC */
            for (int index = 0; index < 4; index++)
            {
                Checksum ^= (byte)((result >> (index * 8)) & 0xFF);
            }

            return (Checksum);
         //   listBox1.Items.Add("CRC: 0x" + crc32a.Value.ToString("X4"));
        }
        public void Send_Frame(byte[] data)
        {
            byte[] frame = new byte[16];
            frame[0] = CMD;
            frame[1] = (byte)data.Length;
            frame[2] = 0;
            frame[3] = COUNTER;
            COUNTER++;
            frame[4] = FRAME_TYPE;

            for(int i = 5; i< (5+data.Length) ;i++)
            {
                frame[i] = (byte)data[i-5];
            }
            for (int i = (5+data.Length); i<13 ; i++)
            {
                frame[i] = 0xFF;
            }
            frame[13] = Crc_Calculate(frame); // Checksum
            frame[14] = 0x0D;
            frame[15] = 0x0A;
            communication.Send_UDP_Data(frame);
            var x = "";
            for(var i = 0; i < frame.Length; i++)
            {
                x = x + "0x" + frame[i].ToString("X2") + "  ";
            }

            showRxPacket(x);
        }

        public void showRxPacket(string rx)
        {
            string unixTimestamp = Convert.ToString((int)DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1)).TotalSeconds);

            string txt = UnixTimestampToDateTime(Double.Parse(unixTimestamp)).ToString() + "  ->  " + rx;
            form1.listBox1.Items.Add(txt);
            form1.listBox1.SelectedIndex = form1.listBox1.Items.Count-1;

        }
        private static DateTime UnixTimestampToDateTime(double unixTime)
        {
            DateTime unixStart = new DateTime(1970, 1, 1, 0, 0, 0, 0, System.DateTimeKind.Utc);
            long unixTimeStampInTicks = (long)(unixTime * TimeSpan.TicksPerSecond);
            return new DateTime(unixStart.Ticks + unixTimeStampInTicks, System.DateTimeKind.Utc);
        }
    }
    
}

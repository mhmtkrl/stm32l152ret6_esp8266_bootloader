using Cave;
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
        byte COUNTER = 0x00;
        byte FRAME_TYPE = 0xCD;

        Form1 form1;
        UDP_Communication communication = new UDP_Communication();

        public void protocol_update(Form1 form)
        {
            form1 = form;
        }
        
        public void Protocol_Init()
        {
            communication.UDP_Comm_Update(this);
            communication.StartProcess();
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
            
        }
        public void Send_Frame(byte cmd, byte subCMD, byte[] data)
        {
            byte[] frame = new byte[16];
            frame[0] = cmd;
            frame[1] = (byte)data.Length;
            frame[2] = COUNTER;
            COUNTER++;
            frame[3] = subCMD;

            for(int i = 4; i< (4+data.Length) ;i++)
            {
                frame[i] = (byte)data[i-4];
            }
            for (int i = (4+data.Length); i<12 ; i++)
            {
                frame[i] = 0xFF;
            }
            byte[] tmp = new byte[12];
            for(int i = 0; i < 12; i++)
            {
                tmp[i] = (byte)frame[i];
            }
            byte checksum = 0xFF;
            if(form1.checkBoxRandomChecksum.Checked == false)
            {
                checksum = Crc_Calculate(tmp);
            }
            frame[12] = checksum; // Checksum
            frame[13] = 0x0D;
            frame[14] = 0x0A;
            communication.Send_UDP_Data(frame);
            
            var x = "";
            for(var i = 0; i < frame.Length; i++)
            {
                x = x + "0x" + frame[i].ToString("X2") + "  ";
            }

            showProtocolPacket(1, x);
        }

        public void showProtocolPacket(byte TxOrRX, string rx)
        {
            string direction = "";

            if (TxOrRX == 0x00)
            {
                direction = " <-- ";
            }
            if (TxOrRX == 0x01)
            {
                direction = " --> ";
            }
            string unixTimestamp = Convert.ToString((int)DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1)).TotalSeconds);
            string txt = UnixTimestampToDateTime(Double.Parse(unixTimestamp)).ToString() + direction + rx;
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

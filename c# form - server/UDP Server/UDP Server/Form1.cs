using Cave;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UDP_Server
{
    public partial class Form1 : Form
    {

        
        UDP_Communication communication = new UDP_Communication();

        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            communication.communication_update(this);
            communication.StartProcess();
            /* CRC32 calculation - nuget */
            CRC32 crc32a = CRC32.MPEG2;
            byte[] data = new byte[8] { 0x4, 0x3, 0x2, 0x1, 0x08, 0x7, 0x6, 0x5 };
            crc32a.Reset();
            crc32a.Update(data);
            listBox1.Items.Add("CRC: 0x" + crc32a.Value.ToString("X4"));

        }

        

        private void buttonLedOn_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x31, 0x0D, 0x0A };
            communication.Send_UDP_Data(data);
        }

       

        private void buttonLedOff_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x30, 0x0D, 0x0A };
            communication.Send_UDP_Data(data);
        }

       

        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        public void showRxPacket(string rx)
        {
            string unixTimestamp = Convert.ToString((int)DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1)).TotalSeconds);

            string txt = UnixTimestampToDateTime(Double.Parse(unixTimestamp)).ToString() + "  -  " + rx;
            listBox1.Items.Add(txt);
            listBox1.SelectedIndex = listBox1.Items.Count-1;
         
        }
        private static DateTime UnixTimestampToDateTime(double unixTime)
        {
            DateTime unixStart = new DateTime(1970, 1, 1, 0, 0, 0, 0, System.DateTimeKind.Utc);
            long unixTimeStampInTicks = (long)(unixTime * TimeSpan.TicksPerSecond);
            return new DateTime(unixStart.Ticks + unixTimeStampInTicks, System.DateTimeKind.Utc);
        }
    }
}

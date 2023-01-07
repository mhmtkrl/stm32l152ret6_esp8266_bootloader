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

        string message = "UDP communication";
        //UDP_Communication communication = new UDP_Communication();
        MyProtocol protocol = new MyProtocol();

        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            protocol.Protocol_Init();
            protocol.protocol_update(this);
        
           

        }

        private void buttonLedOn_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x01, 0x00, 0x01};
            protocol.Send_Frame(data);
        }

        private void buttonLedOff_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x01, 0x00, 0x00};
            protocol.Send_Frame(data);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[] { 0x55, 0x44, 0x50, 0x20, 0x63, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e };
            protocol.Send_Frame(data);
        }
        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
        public void showRxPacket(string rx)
        {
            string unixTimestamp = Convert.ToString((int)DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1)).TotalSeconds);

            string txt = UnixTimestampToDateTime(Double.Parse(unixTimestamp)).ToString() + "  <-  " + rx;
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

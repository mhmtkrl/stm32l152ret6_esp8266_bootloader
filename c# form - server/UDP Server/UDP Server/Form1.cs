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
        private string ESP_IP = "192.168.1.5";
        private int ESP_PORT = 457;
        private UdpClient Esp8266 = new UdpClient(456);
        IAsyncResult process = null;

        public Form1()
        {
            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            StartProcess();
        }

        private void StartProcess()
        {
            process = Esp8266.BeginReceive(Receive, new object());
        }
        private void Receive(IAsyncResult ar)
        {
            IPEndPoint myDevice = new IPEndPoint(IPAddress.Parse(ESP_IP), ESP_PORT);
            byte[] rxData_Byte = Esp8266.EndReceive(ar, ref myDevice);
            listBox1.Items.Add(Encoding.ASCII.GetString(rxData_Byte));
            listBox1.SelectedIndex = listBox1.Items.Count-1;
            StartProcess();
        }

        private void buttonLedOn_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x31, 0x0D, 0x0A };
            Send_UDP_Data(data);
        }

       

        private void buttonLedOff_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x30, 0x0D, 0x0A };
            Send_UDP_Data(data);
        }

        private void Send_UDP_Data(byte[] txData)
        {
            UdpClient Esp8266 = new UdpClient();
            IPEndPoint myDevice = new IPEndPoint(IPAddress.Parse(ESP_IP), ESP_PORT);

            Esp8266.Connect(myDevice);
            Esp8266.Send(txData, txData.Length);
            Esp8266.Close();

            listBox1.Items.Add("Sending: " + Encoding.ASCII.GetString(txData));
            listBox1.SelectedIndex = listBox1.Items.Count-1;
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace UDP_Server
{
    
    internal class UDP_Communication
    {
        Form1 form1;

        private string ESP_IP = "192.168.1.5";
        private int ESP_PORT = 457;
        IAsyncResult process = null;
        private UdpClient Esp8266 = new UdpClient(456);


        public void communication_update(Form1 newForm1)
        {
            form1 = newForm1;
        }

        public void StartProcess()
        {
            process = Esp8266.BeginReceive(Receive, new object());
        }
        private void Receive(IAsyncResult ar)
        {
            IPEndPoint myDevice = new IPEndPoint(IPAddress.Parse(ESP_IP), ESP_PORT);
            byte[] rxData_Byte = Esp8266.EndReceive(ar, ref myDevice);
            form1.showRxPacket(Encoding.ASCII.GetString(rxData_Byte));
            StartProcess();
        }
        public void Send_UDP_Data(byte[] txData)
        {
            UdpClient Esp8266 = new UdpClient();
            IPEndPoint myDevice = new IPEndPoint(IPAddress.Parse(ESP_IP), ESP_PORT);

            Esp8266.Connect(myDevice);
            Esp8266.Send(txData, txData.Length);
            Esp8266.Close();

            form1.listBox1.Items.Add("Sending: " + Encoding.ASCII.GetString(txData));
            form1.listBox1.SelectedIndex = form1.listBox1.Items.Count-1;
        }
    }
}

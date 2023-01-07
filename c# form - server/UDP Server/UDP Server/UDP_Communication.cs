using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UDP_Server
{
    
    internal class UDP_Communication
    {
        public IPEndPoint myDevice = new IPEndPoint(IPAddress.Parse("192.168.1.5"), 457);
        public UdpClient Esp8266 = new UdpClient(456);
        MyProtocol Protocol;

        public void UDP_Comm_Update(MyProtocol myProtocol)
        {
            Protocol = myProtocol;
        }

        public void StartProcess()
        {
            Esp8266.BeginReceive(new AsyncCallback(recv), null);
        }
        private void recv(IAsyncResult res)
        {
            byte[] received = Esp8266.EndReceive(res, ref myDevice);
            var x = "";
            for (var i = 0; i < received.Length; i++)
            {
                x = x + "0x" + received[i].ToString("X2") + "  ";
            }
            Protocol.showProtocolPacket(0, x);
            Protocol.showProtocolPacket(0, Encoding.UTF8.GetString(received));
            Esp8266.BeginReceive(new AsyncCallback(recv), null);
        }
    
        public void Send_UDP_Data(byte[] txData)
        {
            UdpClient Esp8266 = new UdpClient();
            Esp8266.Connect(myDevice);
            Esp8266.Send(txData, txData.Length);
            Esp8266.Close();
        }
    }
}

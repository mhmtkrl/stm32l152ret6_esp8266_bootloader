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
        MyProtocol protocol = new MyProtocol();

        byte ledStatus = 0x00;
        int PacketCount = 100;
        int TxCounter = 0;

        public Form1()
        {
            InitializeComponent();       
        }



        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Interval = 100;
            protocol.protocol_update(this);
            protocol.Protocol_Init();
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

    
        private void buttonClear_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void buttonTestServer_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            ledStatus++;
            if (ledStatus > 1) ledStatus = 0;
            byte[] data = new byte[3] { 0x01, 0x00, ledStatus };
            protocol.Send_Frame(data);
            TxCounter++;
            if (TxCounter == PacketCount)
            {
                TxCounter = 0;
                timer1.Stop();
            }
        }
    }
}

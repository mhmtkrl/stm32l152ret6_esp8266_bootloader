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
        PrepareFile prepareFile = new PrepareFile();

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
            buttonLedOff.Visible = false;
            listBox1.Items.Add("File Size: " + prepareFile.ReadFileGetSize());
        }

        private void buttonLedOn_Click(object sender, EventArgs e)
        {
            buttonLedOff.Visible = true;
            buttonLedOn.Visible = false;
            byte[] data = new byte[3] { 0x01, 0x00, 0x01};
            protocol.Send_Frame(0x01, 0x00, data);
        }

        private void buttonLedOff_Click(object sender, EventArgs e)
        {
            buttonLedOff.Visible = false;
            buttonLedOn.Visible = true;
            byte[] data = new byte[3] { 0x01, 0x00, 0x00};
            protocol.Send_Frame(0x01, 0x00, data);
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
            protocol.Send_Frame(0x01, 0x00, data);
            TxCounter++;
            if (TxCounter == PacketCount)
            {
                TxCounter = 0;
                timer1.Stop();
            }
        }

        private void buttonButonStatus_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x00, 0x01, 0x00 };
            protocol.Send_Frame(0x01, 0x00, data);
        }

        private void buttonTemperatureGet_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x00, 0x02, 0x00 };
            protocol.Send_Frame(0x01, 0x00, data);
        }

        private void buttonLEDget_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x00, 0x00, 0x00 };
            protocol.Send_Frame(0x01, 0x00, data);
        }

        private void buttonDeviceInformation_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[3] { 0x00, 0x00, 0x00 };
            protocol.Send_Frame(0x02, 0x00, data);
        }

        private void buttonErase_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[1] { 0xFF };
            protocol.Send_Frame(0x03, 0x00, data);
        }

        private void buttonSendByteArray_Click(object sender, EventArgs e)
        {
            byte[] data = prepareFile.SplitFile();
            protocol.Send_Frame(0x03, 0x01, data);
        }

        private void buttonReadByteArray_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[8] { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
            protocol.Send_Frame(0x03, 0x02, data);
        }
    }
}

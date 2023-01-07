﻿using Cave;
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
     
    }
}
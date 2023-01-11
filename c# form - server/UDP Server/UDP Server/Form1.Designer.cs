namespace UDP_Server
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonLedOn = new System.Windows.Forms.Button();
            this.buttonLedOff = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonLEDget = new System.Windows.Forms.Button();
            this.buttonClear = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.checkBoxRandomChecksum = new System.Windows.Forms.CheckBox();
            this.buttonTestServer = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.buttonDeviceInformation = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.buttonTemperatureGet = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.buttonButonStatus = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.buttonSendByteArray = new System.Windows.Forms.Button();
            this.buttonErase = new System.Windows.Forms.Button();
            this.buttonReadByteArray = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.panel2.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.listBox1.Font = new System.Drawing.Font("Nirmala UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.listBox1.ForeColor = System.Drawing.SystemColors.Info;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 17;
            this.listBox1.Location = new System.Drawing.Point(3, 25);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(707, 565);
            this.listBox1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(268, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(159, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Received Packets From STM32";
            // 
            // buttonLedOn
            // 
            this.buttonLedOn.Location = new System.Drawing.Point(10, 19);
            this.buttonLedOn.Name = "buttonLedOn";
            this.buttonLedOn.Size = new System.Drawing.Size(74, 38);
            this.buttonLedOn.TabIndex = 2;
            this.buttonLedOn.Text = "ON";
            this.buttonLedOn.UseVisualStyleBackColor = true;
            this.buttonLedOn.Click += new System.EventHandler(this.buttonLedOn_Click);
            // 
            // buttonLedOff
            // 
            this.buttonLedOff.Location = new System.Drawing.Point(10, 19);
            this.buttonLedOff.Name = "buttonLedOff";
            this.buttonLedOff.Size = new System.Drawing.Size(74, 38);
            this.buttonLedOff.TabIndex = 2;
            this.buttonLedOff.Text = "OFF";
            this.buttonLedOff.UseVisualStyleBackColor = true;
            this.buttonLedOff.Click += new System.EventHandler(this.buttonLedOff_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonLEDget);
            this.groupBox1.Controls.Add(this.buttonLedOn);
            this.groupBox1.Controls.Add(this.buttonLedOff);
            this.groupBox1.Location = new System.Drawing.Point(8, 19);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(186, 69);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "LED Control";
            // 
            // buttonLEDget
            // 
            this.buttonLEDget.Location = new System.Drawing.Point(106, 19);
            this.buttonLEDget.Name = "buttonLEDget";
            this.buttonLEDget.Size = new System.Drawing.Size(74, 38);
            this.buttonLEDget.TabIndex = 0;
            this.buttonLEDget.Text = "GET";
            this.buttonLEDget.UseVisualStyleBackColor = true;
            this.buttonLEDget.Click += new System.EventHandler(this.buttonLEDget_Click);
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(296, 596);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(71, 23);
            this.buttonClear.TabIndex = 4;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.panel3);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(945, 641);
            this.panel1.TabIndex = 5;
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.groupBox6);
            this.panel3.Controls.Add(this.groupBox7);
            this.panel3.Controls.Add(this.groupBox5);
            this.panel3.Controls.Add(this.groupBox2);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel3.Location = new System.Drawing.Point(716, 0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(229, 641);
            this.panel3.TabIndex = 6;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.checkBoxRandomChecksum);
            this.groupBox6.Controls.Add(this.buttonTestServer);
            this.groupBox6.Location = new System.Drawing.Point(17, 514);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(199, 124);
            this.groupBox6.TabIndex = 7;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "TRANSMISSION TEST";
            // 
            // checkBoxRandomChecksum
            // 
            this.checkBoxRandomChecksum.AutoSize = true;
            this.checkBoxRandomChecksum.Location = new System.Drawing.Point(38, 91);
            this.checkBoxRandomChecksum.Name = "checkBoxRandomChecksum";
            this.checkBoxRandomChecksum.Size = new System.Drawing.Size(119, 17);
            this.checkBoxRandomChecksum.TabIndex = 5;
            this.checkBoxRandomChecksum.Text = "Random Checksum";
            this.checkBoxRandomChecksum.UseVisualStyleBackColor = true;
            // 
            // buttonTestServer
            // 
            this.buttonTestServer.Location = new System.Drawing.Point(48, 32);
            this.buttonTestServer.Name = "buttonTestServer";
            this.buttonTestServer.Size = new System.Drawing.Size(101, 44);
            this.buttonTestServer.TabIndex = 4;
            this.buttonTestServer.Text = "TEST SERVER";
            this.buttonTestServer.UseVisualStyleBackColor = true;
            this.buttonTestServer.Click += new System.EventHandler(this.buttonTestServer_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.buttonDeviceInformation);
            this.groupBox5.Location = new System.Drawing.Point(17, 265);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(199, 81);
            this.groupBox5.TabIndex = 6;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "DEVICE INFORMATION";
            // 
            // buttonDeviceInformation
            // 
            this.buttonDeviceInformation.Location = new System.Drawing.Point(60, 28);
            this.buttonDeviceInformation.Name = "buttonDeviceInformation";
            this.buttonDeviceInformation.Size = new System.Drawing.Size(74, 38);
            this.buttonDeviceInformation.TabIndex = 0;
            this.buttonDeviceInformation.Text = "GET";
            this.buttonDeviceInformation.UseVisualStyleBackColor = true;
            this.buttonDeviceInformation.Click += new System.EventHandler(this.buttonDeviceInformation_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.groupBox4);
            this.groupBox2.Controls.Add(this.groupBox3);
            this.groupBox2.Controls.Add(this.groupBox1);
            this.groupBox2.Location = new System.Drawing.Point(17, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 250);
            this.groupBox2.TabIndex = 5;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "PERIPHERAL CONTROL";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.buttonTemperatureGet);
            this.groupBox4.Location = new System.Drawing.Point(8, 167);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(186, 68);
            this.groupBox4.TabIndex = 4;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Temperature";
            // 
            // buttonTemperatureGet
            // 
            this.buttonTemperatureGet.Location = new System.Drawing.Point(57, 18);
            this.buttonTemperatureGet.Name = "buttonTemperatureGet";
            this.buttonTemperatureGet.Size = new System.Drawing.Size(74, 38);
            this.buttonTemperatureGet.TabIndex = 0;
            this.buttonTemperatureGet.Text = "GET";
            this.buttonTemperatureGet.UseVisualStyleBackColor = true;
            this.buttonTemperatureGet.Click += new System.EventHandler(this.buttonTemperatureGet_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.buttonButonStatus);
            this.groupBox3.Location = new System.Drawing.Point(8, 94);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(186, 68);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Button Status";
            // 
            // buttonButonStatus
            // 
            this.buttonButonStatus.Location = new System.Drawing.Point(57, 18);
            this.buttonButonStatus.Name = "buttonButonStatus";
            this.buttonButonStatus.Size = new System.Drawing.Size(74, 38);
            this.buttonButonStatus.TabIndex = 0;
            this.buttonButonStatus.Text = "GET";
            this.buttonButonStatus.UseVisualStyleBackColor = true;
            this.buttonButonStatus.Click += new System.EventHandler(this.buttonButonStatus_Click);
            // 
            // panel2
            // 
            this.panel2.AutoSize = true;
            this.panel2.Controls.Add(this.listBox1);
            this.panel2.Controls.Add(this.buttonClear);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(713, 641);
            this.panel2.TabIndex = 5;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.buttonErase);
            this.groupBox7.Controls.Add(this.buttonReadByteArray);
            this.groupBox7.Controls.Add(this.buttonSendByteArray);
            this.groupBox7.Location = new System.Drawing.Point(17, 352);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(199, 156);
            this.groupBox7.TabIndex = 6;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "FIRMWARE UPDATE";
            // 
            // buttonSendByteArray
            // 
            this.buttonSendByteArray.Location = new System.Drawing.Point(22, 62);
            this.buttonSendByteArray.Name = "buttonSendByteArray";
            this.buttonSendByteArray.Size = new System.Drawing.Size(154, 38);
            this.buttonSendByteArray.TabIndex = 0;
            this.buttonSendByteArray.Text = "SEND BYTE ARRAY";
            this.buttonSendByteArray.UseVisualStyleBackColor = true;
            this.buttonSendByteArray.Click += new System.EventHandler(this.buttonSendByteArray_Click);
            // 
            // buttonErase
            // 
            this.buttonErase.Location = new System.Drawing.Point(22, 19);
            this.buttonErase.Name = "buttonErase";
            this.buttonErase.Size = new System.Drawing.Size(154, 38);
            this.buttonErase.TabIndex = 0;
            this.buttonErase.Text = "ERASE";
            this.buttonErase.UseVisualStyleBackColor = true;
            this.buttonErase.Click += new System.EventHandler(this.buttonErase_Click);
            // 
            // buttonReadByteArray
            // 
            this.buttonReadByteArray.Location = new System.Drawing.Point(22, 106);
            this.buttonReadByteArray.Name = "buttonReadByteArray";
            this.buttonReadByteArray.Size = new System.Drawing.Size(154, 38);
            this.buttonReadByteArray.TabIndex = 0;
            this.buttonReadByteArray.Text = "READ BYTE ARRAY";
            this.buttonReadByteArray.UseVisualStyleBackColor = true;
            this.buttonReadByteArray.Click += new System.EventHandler(this.buttonReadByteArray_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(945, 641);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonLedOn;
        private System.Windows.Forms.Button buttonLedOff;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel3;
        public System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button buttonTestServer;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button buttonTemperatureGet;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button buttonButonStatus;
        private System.Windows.Forms.Button buttonLEDget;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button buttonDeviceInformation;
        private System.Windows.Forms.GroupBox groupBox6;
        public System.Windows.Forms.CheckBox checkBoxRandomChecksum;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.Button buttonSendByteArray;
        private System.Windows.Forms.Button buttonErase;
        private System.Windows.Forms.Button buttonReadByteArray;
    }
}


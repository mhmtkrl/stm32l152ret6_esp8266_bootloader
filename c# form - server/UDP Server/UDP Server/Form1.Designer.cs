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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonLedOn = new System.Windows.Forms.Button();
            this.buttonLedOff = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonClear = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(29, 38);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(296, 342);
            this.listBox1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(90, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(159, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Received Packets From STM32";
            // 
            // buttonLedOn
            // 
            this.buttonLedOn.Location = new System.Drawing.Point(6, 19);
            this.buttonLedOn.Name = "buttonLedOn";
            this.buttonLedOn.Size = new System.Drawing.Size(75, 23);
            this.buttonLedOn.TabIndex = 2;
            this.buttonLedOn.Text = "ON";
            this.buttonLedOn.UseVisualStyleBackColor = true;
            this.buttonLedOn.Click += new System.EventHandler(this.buttonLedOn_Click);
            // 
            // buttonLedOff
            // 
            this.buttonLedOff.Location = new System.Drawing.Point(87, 19);
            this.buttonLedOff.Name = "buttonLedOff";
            this.buttonLedOff.Size = new System.Drawing.Size(75, 23);
            this.buttonLedOff.TabIndex = 2;
            this.buttonLedOff.Text = "OFF";
            this.buttonLedOff.UseVisualStyleBackColor = true;
            this.buttonLedOff.Click += new System.EventHandler(this.buttonLedOff_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonLedOff);
            this.groupBox1.Controls.Add(this.buttonLedOn);
            this.groupBox1.Location = new System.Drawing.Point(331, 38);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(166, 52);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "LED Control";
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(124, 386);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(71, 23);
            this.buttonClear.TabIndex = 4;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(508, 441);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonLedOn;
        private System.Windows.Forms.Button buttonLedOff;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonClear;
    }
}


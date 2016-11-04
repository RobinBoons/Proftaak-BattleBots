namespace VisualController
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.cbAvailablePortsController = new System.Windows.Forms.ComboBox();
            this.btnConnectController = new System.Windows.Forms.Button();
            this.lbMessages = new System.Windows.Forms.ListBox();
            this.SerialPortController = new System.IO.Ports.SerialPort(this.components);
            this.btnConnectRP6 = new System.Windows.Forms.Button();
            this.cbAvailablePortsRP6 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SerialPortRP6 = new System.IO.Ports.SerialPort(this.components);
            this.lblControllerStatus = new System.Windows.Forms.Label();
            this.lblRP6Status = new System.Windows.Forms.Label();
            this.lblGameState = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // cbAvailablePortsController
            // 
            this.cbAvailablePortsController.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbAvailablePortsController.FormattingEnabled = true;
            this.cbAvailablePortsController.Location = new System.Drawing.Point(12, 34);
            this.cbAvailablePortsController.Name = "cbAvailablePortsController";
            this.cbAvailablePortsController.Size = new System.Drawing.Size(121, 21);
            this.cbAvailablePortsController.TabIndex = 0;
            // 
            // btnConnectController
            // 
            this.btnConnectController.Location = new System.Drawing.Point(139, 33);
            this.btnConnectController.Name = "btnConnectController";
            this.btnConnectController.Size = new System.Drawing.Size(75, 21);
            this.btnConnectController.TabIndex = 1;
            this.btnConnectController.Text = "Connect";
            this.btnConnectController.UseVisualStyleBackColor = true;
            this.btnConnectController.Click += new System.EventHandler(this.btnConnectController_Click);
            // 
            // lbMessages
            // 
            this.lbMessages.FormattingEnabled = true;
            this.lbMessages.Location = new System.Drawing.Point(12, 62);
            this.lbMessages.Name = "lbMessages";
            this.lbMessages.Size = new System.Drawing.Size(202, 212);
            this.lbMessages.TabIndex = 2;
            // 
            // SerialPortController
            // 
            this.SerialPortController.BaudRate = 36000;
            this.SerialPortController.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPortController_DataReceived);
            // 
            // btnConnectRP6
            // 
            this.btnConnectRP6.Location = new System.Drawing.Point(347, 34);
            this.btnConnectRP6.Name = "btnConnectRP6";
            this.btnConnectRP6.Size = new System.Drawing.Size(75, 21);
            this.btnConnectRP6.TabIndex = 4;
            this.btnConnectRP6.Text = "Connect";
            this.btnConnectRP6.UseVisualStyleBackColor = true;
            this.btnConnectRP6.Click += new System.EventHandler(this.btnConnectRP6_Click);
            // 
            // cbAvailablePortsRP6
            // 
            this.cbAvailablePortsRP6.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbAvailablePortsRP6.FormattingEnabled = true;
            this.cbAvailablePortsRP6.Location = new System.Drawing.Point(220, 35);
            this.cbAvailablePortsRP6.Name = "cbAvailablePortsRP6";
            this.cbAvailablePortsRP6.Size = new System.Drawing.Size(121, 21);
            this.cbAvailablePortsRP6.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Controller";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(220, 12);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(28, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "RP6";
            // 
            // SerialPortRP6
            // 
            this.SerialPortRP6.BaudRate = 36000;
            this.SerialPortRP6.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPortRP6_DataReceived);
            // 
            // lblControllerStatus
            // 
            this.lblControllerStatus.AutoSize = true;
            this.lblControllerStatus.Location = new System.Drawing.Point(231, 87);
            this.lblControllerStatus.Name = "lblControllerStatus";
            this.lblControllerStatus.Size = new System.Drawing.Size(123, 13);
            this.lblControllerStatus.TabIndex = 7;
            this.lblControllerStatus.Text = "Controller not connected";
            // 
            // lblRP6Status
            // 
            this.lblRP6Status.AutoSize = true;
            this.lblRP6Status.Location = new System.Drawing.Point(231, 100);
            this.lblRP6Status.Name = "lblRP6Status";
            this.lblRP6Status.Size = new System.Drawing.Size(100, 13);
            this.lblRP6Status.TabIndex = 8;
            this.lblRP6Status.Text = "RP6 not connected";
            // 
            // lblGameState
            // 
            this.lblGameState.AutoSize = true;
            this.lblGameState.Location = new System.Drawing.Point(231, 113);
            this.lblGameState.Name = "lblGameState";
            this.lblGameState.Size = new System.Drawing.Size(96, 13);
            this.lblGameState.TabIndex = 9;
            this.lblGameState.Text = "Game has stopped";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(434, 282);
            this.Controls.Add(this.lblGameState);
            this.Controls.Add(this.lblRP6Status);
            this.Controls.Add(this.lblControllerStatus);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnConnectRP6);
            this.Controls.Add(this.cbAvailablePortsRP6);
            this.Controls.Add(this.lbMessages);
            this.Controls.Add(this.btnConnectController);
            this.Controls.Add(this.cbAvailablePortsController);
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cbAvailablePortsController;
        private System.Windows.Forms.Button btnConnectController;
        private System.Windows.Forms.ListBox lbMessages;
        private System.IO.Ports.SerialPort SerialPortController;
        private System.Windows.Forms.Button btnConnectRP6;
        private System.Windows.Forms.ComboBox cbAvailablePortsRP6;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.IO.Ports.SerialPort SerialPortRP6;
        private System.Windows.Forms.Label lblControllerStatus;
        private System.Windows.Forms.Label lblRP6Status;
        private System.Windows.Forms.Label lblGameState;
    }
}


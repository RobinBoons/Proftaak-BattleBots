using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using BattleBotClient;

namespace VisualController
{
    public partial class Form1 : Form
    {
        string incomingMessage;
        string incomingMessage2;
        Client client;
        GameState currentState;

        public Form1()
        {
            InitializeComponent();

            currentState = GameState.Stopped;

            getAvailablePorts();
            client = new Client(3, "192.168.137.1", 5000);

            client.GameStarted += Client_GameStarted;
            client.GamePaused += Client_GamePaused;
            client.GameStopped += Client_GameStopped;
        }

        private void Client_GameStarted(object sender, EventArgs e)
        {
            MessageBox.Show("The game has started!");
            sendToRP6("%START$");
            lblGameState.Text = "Game is running";
            currentState = GameState.Running;
        }

        private void Client_GamePaused(object sender, EventArgs e)
        {
            MessageBox.Show("The game has been paused!");
            sendToRP6("%PSD$");
            lblGameState.Text = "Game is paused";
            currentState = GameState.Paused;
        }

        private void Client_GameStopped(object sender, EventArgs e)
        {
            MessageBox.Show("The game has stopped!");
            sendToRP6("%STP$");
            lblGameState.Text = "Game is stopped";
            currentState = GameState.Stopped;
        }

        private void getAvailablePorts()
        {
            String[] ports = SerialPort.GetPortNames();
            cbAvailablePortsController.Items.AddRange(ports);
            cbAvailablePortsRP6.Items.AddRange(ports);
        }

        private void btnConnectController_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortController.PortName = cbAvailablePortsController.Text;
                SerialPortController.Open();
                lbMessages.Items.Insert(0, "verbonden!");
                lblControllerStatus.Text = "Controller is connected";
            }
            catch
            {
                lbMessages.Items.Insert(0, "selecteer eerst een poort!");
            }
        }

        private void SerialPortController_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            incomingMessage = SerialPortController.ReadExisting();
            this.Invoke(new EventHandler(DisplayText));
            incomingMessage = "";
            sendToRP6(incomingMessage);
        }

        private void DisplayText(object sender, EventArgs e)
        {
            lbMessages.Items.Insert(0, incomingMessage);
            incomingMessage = "";
        }

        private void DisplayText2(object sender, EventArgs e)
        {
            lbMessages.Items.Insert(0, incomingMessage2);
            incomingMessage = "";
        }
        private void btnConnectRP6_Click(object sender, EventArgs e)
        {
            try
            {
                SerialPortRP6.PortName = cbAvailablePortsRP6.Text;
                SerialPortRP6.Open();
                lbMessages.Items.Insert(0, "verbonden!");
                lblRP6Status.Text = "RP6 is connected";
            }
            catch
            {
                lbMessages.Items.Insert(0, "selecteer eerst een poort!");
            }
        }

        private void sendToRP6(string message)
        {
            if (SerialPortRP6.IsOpen && currentState == GameState.Running)
            {
               SerialPortRP6.Write(message);
            }
            else
            {
                MessageBox.Show("'Sup dude it ain't working yo");
            }
        }

        private void SerialPortRP6_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            incomingMessage2 = SerialPortRP6.ReadExisting();
            this.Invoke(new EventHandler(DisplayText2));

            if(incomingMessage2 == "%HIT$")
            {
                client.HitSomeone();
            }
            else if(incomingMessage2 == "%OUCH$")
            {
                client.GotHit();
            }

            incomingMessage2 = "";
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                sendToRP6("%FWD$");
            }
            else if (e.KeyCode == Keys.Left)
            {
                sendToRP6("%LFT$");
            }
            else if (e.KeyCode == Keys.Right)
            {
                sendToRP6("%RGT$");
            } 
            else if (e.KeyCode == Keys.Down)
            {
                sendToRP6("%BKW$");
            }
    }
    }
}

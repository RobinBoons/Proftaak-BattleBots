using System;
using System.Windows.Forms;
using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;

namespace mqttexampleclient
{
    public partial class Form1 : Form
    {
        MqttClient client=null;

        public Form1()
        {
            InitializeComponent();

            // create client instance 
             client = new MqttClient("mqtt.fhict.nl");

            // register to message received 
            client.MqttMsgPublishReceived += client_MqttMsgPublishReceived;

            string clientId = Guid.NewGuid().ToString();
            client.Connect(clientId, "i339322_timojansen", "Xjr1MGsdYEKtJ5");

            // subscribe to the topic "/home/temperature" with QoS 2 
            client.Subscribe(new string[] { "public/i339322_timojansen/#" }, new byte[] { MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE });
        }

        void client_MqttMsgPublishReceived(object sender, MqttMsgPublishEventArgs e)
        {
            // handle message received 
          
            // From byte array to string
            string s = System.Text.Encoding.UTF8.GetString(e.Message, 0, e.Message.Length);
            // methods on UI items need to be called via the invoke method
            // this is because the received method is called from another thread
            this.Invoke((MethodInvoker)(() => listBox1.Items.Add(s.ToString())));
          

        }

    }




 
}

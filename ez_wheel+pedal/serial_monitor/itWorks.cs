using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO.Ports;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            SerialPort port = new SerialPort();
            port.BaudRate = 9600;
            port.PortName = "COM5";
            port.Handshake = Handshake.None;
            port.Open();

            port.ReadTimeout = 500;
            port.WriteTimeout = 500;




            while (true)
            {
                try
                {
                    int b = port.BytesToRead;
                    if (b > 0)
                    {
                        // Print Serial line
                        // Byte[] ioBuffer = new Byte[b];
                        // port.Read(ioBuffer, offset: 0, count: b);
                        // foreach (Byte i in ioBuffer)
                        // {
                        //     Console.Write((char)i);
                        // }
                        // Alternative, does same thing

                        //Console.WriteLine("trying...");
                        // string line = "";

                        while (b > 0)
                        {
                            //((char)(port.ReadByte())).ToString();
                            char char1 = (char)port.ReadByte();
                            char char2 = (char)port.ReadByte();

                            if (char1 == 'f')
                            {
                                // Forward
                                //Console.Write("forward");
                                SendKeys.SendWait("w");
                            }
                            else if (char1 == 'b')
                            {
                                // Backward
                                //Console.Write("backward");
                                SendKeys.SendWait("s");
                            }
                            else
                            {
                                //Console.Write("straight");
                            }
                            if (char2 == 'l')
                            {
                                //Console.Write(" + left");
                                SendKeys.SendWait("d");
                            }
                            else if (char2 == 'r')
                            {
                                // Forward + right
                                //Console.Write(" + right");
                                SendKeys.SendWait("a");
                            }
                            Console.WriteLine("Char1: " + char1 + "\n" + "Char2: "+ char2);
                            char1 = ' ';
                            char2 = ' ';
                        }
                        // int t = (int)liner;
                        // Console.WriteLine(t);
                        // if (liner == 'f')
                        // {
                        //     Console.WriteLine("FINALLY");
                        // }
                    }
                }
                catch (System.TimeoutException)
                {
                    Console.WriteLine("Read timed out");
                    //throw;
                }
                catch (System.Exception)
                {
                    Console.WriteLine("failing...");
                    throw;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Thread.Sleep(3000);
            SendKeys.SendWait("W");
        }
    }
}

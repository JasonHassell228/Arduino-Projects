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
using System.Runtime.InteropServices;
using System.Net;
using System.Net.Sockets;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            SerialPort port = new SerialPort();
            port.BaudRate = 9600;
            port.Handshake = Handshake.None;
            port.ReadTimeout = 500;
            port.WriteTimeout = 500;

            string[] ports = SerialPort.GetPortNames();

            foreach (String portName in ports)
            {
                try
                {
                    Console.WriteLine("Trying: ");

                    port.PortName = portName;
                    port.Open();

                    port.WriteLine("q");
                    char read = (char)port.ReadByte();
                    if (read == 'g')
                    {
                        port.WriteLine("q");
                        Console.WriteLine(portName);
                        Console.WriteLine("This Com was found new");
                        Keyboard.KeyDown((byte)Keys.D1);
                        Keyboard.KeyUp((byte)Keys.D1);
                        break;
                    }
                    /*
                    else
                    {
                        port.Close();
                    }
                    */
                }
                catch (System.Exception)
                {
                    Console.WriteLine("Broke dick piece of shit COM port");
                    //throw;
                }
            }


            /*
            int i = 0;
            {
                while (true)
                {
                    string[] serialPorts = SerialPort.GetPortNames();
                    try
                    {
                        port.PortName = serialPorts[i];
                        break;
                    }
                    catch (System.Exception)
                    {
                        Console.WriteLine("No port found");
                        if (i < 30)
                        {
                            i += 1;
                        }
                        else
                        {
                            i = 0;
                        }
                        //throw;
                    }
                }
            }
            */

            while (true)
            {
                //Console.WriteLine(FreeTcpPort());
                try
                {
                    int b = port.BytesToRead;
                    //Console.WriteLine(b);
                    if (b > 0)
                    {
                        while (b > 0)
                        {
                            char char1 = (char)port.ReadByte();
                            char char2 = (char)port.ReadByte();

                            if (char1 == 'f')
                            {
                                //forward
                                Keyboard.KeyUp((byte)Keys.S);
                                Keyboard.KeyDown((byte)Keys.W);
                            }
                            else if (char1 == 'b')
                            {
                                //back
                                Keyboard.KeyUp((byte)Keys.W);
                                Keyboard.KeyDown((byte)Keys.S);
                            }
                            else
                            {
                                //stop
                                Keyboard.KeyUp((byte)Keys.W);
                                Keyboard.KeyUp((byte)Keys.S);
                            }

                            if (char2 == 'l')
                            {
                                //left
                                Keyboard.KeyUp((byte)Keys.D);
                                Keyboard.KeyDown((byte)Keys.A);
                            }
                            else if (char2 == 'r')
                            {
                                //right
                                Keyboard.KeyUp((byte)Keys.A);
                                Keyboard.KeyDown((byte)Keys.D);
                            }
                            else
                            {
                                //straight
                                Keyboard.KeyUp((byte)Keys.D);
                                Keyboard.KeyUp((byte)Keys.A);
                            }

                            Console.WriteLine("Char1: " + char1 + " | " + "Char2: " + char2);
                            char1 = ' ';
                            char2 = ' ';
                        }
                    }
                }
                catch (System.TimeoutException)
                {
                    Console.WriteLine("Read timed out");
                }
                catch (System.Exception)
                {
                    Console.WriteLine("failing...");
                    //throw;
                }
            }
        }
        /*
        static int FreeTcpPort()
        {
            TcpListener l = new TcpListener(IPAddress.Loopback, 0);
            l.Start();
            int port = ((IPEndPoint)l.LocalEndpoint).Port;
            l.Stop();
            return port;
        }
        */

        private void button1_Click(object sender, EventArgs e)
        {
            Thread.Sleep(3000);
            SendKeys.SendWait("W");
        }
    }
}



public class Keyboard
{
    [DllImport("user32.dll", SetLastError = true)]
    static extern void keybd_event(byte bVk, byte bScan, int dwFlags, int dwExtraInfo);

    const int KEY_DOWN_EVENT = 0x0001; //Key down flag
    const int KEY_UP_EVENT = 0x0002; //Key up flag
    const int PauseBetweenStrokes = 50; // Ms between key presses

    public static void KeyDown(byte key)
    {
        keybd_event(key, 0, KEY_DOWN_EVENT, 0);
    }
    public static void KeyUp(byte key)
    {
        keybd_event(key, 0, KEY_UP_EVENT, 0);
    }
}

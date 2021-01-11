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
                    //Console.WriteLine(b);
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
                                //SendKeys.SendWait("w");
                                Keyboard.HoldKey((byte)Keys.W, 100);

                                if (char2 == 'l')
                                {
                                    //Console.Write(" + left");
                                    //SendKeys.SendWait("d");
                                    Keyboard.HoldKey((byte)Keys.A, 100);
                                }
                                else if (char2 == 'r')
                                {
                                    // Forward + right
                                    //Console.Write(" + right");
                                    //SendKeys.SendWait("a");
                                    Keyboard.HoldKey((byte)Keys.D, 100);
                                }
                            }
                            else if (char1 == 'b')
                            {
                                // Backward
                                //Console.Write("backward");
                                //SendKeys.SendWait("s");
                                Keyboard.HoldKey((byte)Keys.S, 100);

                                if (char2 == 'l')
                                {
                                    //Console.Write(" + left");
                                    //SendKeys.SendWait("d");
                                    Keyboard.HoldKey((byte)Keys.A, 100);
                                }
                                else if (char2 == 'r')
                                {
                                    // Forward + right
                                    //Console.Write(" + right");
                                    //SendKeys.SendWait("a");
                                    Keyboard.HoldKey((byte)Keys.D, 100);
                                }
                            }
                            else if (char1 == 'l')
                            {
                                //SendKeys.SendWait("a");
                                Keyboard.HoldKey((byte)Keys.A, 100);
                                /*
                                new Thread(() =>
                                {
                                    Thread.CurrentThread.IsBackground = true;
                                    // run your code here
                                    for(int i=0; i<10; i++)
                                    {
                                        Console.WriteLine("Hello, world");
                                        Thread.Sleep(100);
                                    }
                                }).Start();
                                */
                                //keybd_event(key, 0, KEY_DOWN_EVENT, 0);
                            }
                            else if (char1 == 'r')
                            {
                                //SendKeys.SendWait("d");
                                Keyboard.HoldKey((byte)Keys.D, 100);
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



public class Keyboard
{
    [DllImport("user32.dll", SetLastError = true)]
    static extern void keybd_event(byte bVk, byte bScan, int dwFlags, int dwExtraInfo);

    const int KEY_DOWN_EVENT = 0x0001; //Key down flag
    const int KEY_UP_EVENT = 0x0002; //Key up flag
    const int PauseBetweenStrokes = 50; // Ms between key presses

    public static void HoldKey(byte key, int duration)
    {
        //int totalDuration = 0;
        //while (totalDuration < duration)
        {
            keybd_event(key, 0, KEY_DOWN_EVENT, 0);
            keybd_event(key, 0, KEY_UP_EVENT, 0);
            //System.Threading.Thread.Sleep(PauseBetweenStrokes);
            //totalDuration += PauseBetweenStrokes;
        }
    }
}

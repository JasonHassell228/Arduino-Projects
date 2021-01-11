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
                        while (b > 0)
                        {
                            char char1 = (char)port.ReadByte();
                            char char2 = (char)port.ReadByte();

                            if (char1 == 'f')
                            {
                                Keyboard.KeyDown((byte)Keys.W);

                                if (char2 == 'l')
                                {
                                    Keyboard.KeyDown((byte)Keys.A);
                                }
                                else if (char2 == 'r')
                                {
                                    Keyboard.KeyDown((byte)Keys.D);
                                }
                            }
                            else if (char1 == 'b')
                            {
                                Keyboard.KeyDown((byte)Keys.S);

                                if (char2 == 'l')
                                {
                                    Keyboard.KeyDown((byte)Keys.A);
                                }
                                else if (char2 == 'r')
                                {
                                    Keyboard.KeyDown((byte)Keys.D);
                                }
                            }
                            else if (char1 == 'l')
                            {
                                Keyboard.KeyDown((byte)Keys.A);
                            }
                            else if (char1 == 'r')
                            {
                                Keyboard.KeyDown((byte)Keys.D);
                            }

                            Console.WriteLine("Char1: " + char1 + " | " + "Char2: "+ char2);
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

    public static void KeyDown(byte key)
    {
        keybd_event(key, 0, KEY_DOWN_EVENT, 0);
    }
    public static void KeyUp(byte key)
    {
        keybd_event(key, 0, KEY_UP_EVENT, 0);
    }
}

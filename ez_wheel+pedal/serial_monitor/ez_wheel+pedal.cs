using System;
using System.IO.Ports;
using System.Windows.Forms;

class SerialPortProgram
{
    static void DataReceivedHandler(Object sender, SerialDataReceivedEventArgs e)
    {
        Console.WriteLine("at least i get here now???");
        SerialPort sp = (SerialPort)sender;
        string dataIn = sp.ReadExisting();
        Console.Write("Data: ");
        Console.WriteLine(dataIn);
    }

    static void Main(string[] args)
    {
        SerialPort port = new SerialPort();
        port.BaudRate = 9600;
        port.PortName = "COM5";
        port.Handshake = Handshake.None;
        port.Open();

        port.ReadTimeout = 500;
        port.WriteTimeout = 500;

        var portNames = SerialPort.GetPortNames();

        // foreach(var porty in portNames) {
        //     //Try for every portName and break on the first working
        //     try
        //     {
        //         port.PortName = porty.ToString();
        //         Console.Write("Using port ");
        //         Console.WriteLine(porty);
        //     }
        //     catch (System.Exception)
        //     {
        //         Console.Write("Port ");
        //         Console.Write(porty);
        //         Console.WriteLine(" failed");
        //     }
        // }

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
                        char char1;
                        char1 = (char)port.ReadByte();
                        char char2 = (char)port.ReadByte();

                        if (char1 == 'f')
                        {
                            // Forward
                            Console.Write("forward");
                            // try
                            // {
                            //     SendKeys.Send("W");
                            // }
                            // catch (System.Exception)
                            // {
                            //     Console.WriteLine("fuck off");
                            //     throw;
                            // }
                        }
                        else if (char1 == 'b')
                        {
                            // Backward
                            Console.Write("backward");
                        }
                        else
                        {
                            //Console.Write("straight");
                        }
                        if (char2 == 'l')
                        {
                            Console.Write(" + left");
                        }
                        else if (char2 == 'r')
                        {
                            // Forward + right
                            Console.Write(" + right");
                        }
                        Console.WriteLine();
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
}

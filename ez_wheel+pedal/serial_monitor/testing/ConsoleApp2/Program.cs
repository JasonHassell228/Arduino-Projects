using System;
using WindowsInput;
using WindowsInput.Native;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            InputSimulator sim = new InputSimulator();
            sim.Keyboard.KeyPress(VirtualKeyCode.VK_W);
        }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UDP_Server
{
    internal class PrepareFile
    {
        private string FilePath =  "c:\\Users\\mehme\\Embedded Systems\\FOTA\\stm32l152ret6_esp8266_bootloader\\Code.bin";
        private byte[] FileData = new byte[2130702268];

        public int ReadFileGetSize()
        {
            FileData = File.ReadAllBytes(FilePath); 
            return FileData.Length;
        }
        public byte[] SplitFile()
        {
            string txt = "";
            byte[] data = new byte[8];
            for(int i = 0; i < 8; i++)
            {
                txt = txt + FileData[i].ToString("X2") + " ";
                data[i] = FileData[i];
            }
            return data;
        }
    }
}

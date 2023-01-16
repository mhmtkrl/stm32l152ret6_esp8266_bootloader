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
        List<byte[]> Program = new List<byte[]>();

        public int ReadFileGetSize()
        {
            FileData = File.ReadAllBytes(FilePath);
            Program.Add(FileData);
            return FileData.Length;
        }

        public List<byte[]> ParseData()
        {
            List<byte[]> listRange = new List<byte[]>();

            byte[] sum = new byte[8] { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
            int mod = (FileData.Length%8);
            for (int i = 0; i < mod; i++)
            {
                sum[i] = FileData[FileData.Length - mod + i];
            }


            for(int i = 0; i < FileData.Length/8 ; i++)
            {
                byte[] data = new byte[8];

                for (int j = 0; j < 8; j++)
                {
                    data[j] = FileData[j + i*8];
                }
                listRange.Add(data);
            }

            listRange.Add(sum);

            return listRange;
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

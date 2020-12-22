using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace AdmiralFishing
{
    class Memory
    {
        //handle of process we are attached to
        private static IntPtr handle = IntPtr.Zero;

        /// <summary>
        /// Get handle to process with read and write permissions.
        /// </summary>
        /// <param name="pId">process ID</param>
        /// <returns>handle</returns>
        public static IntPtr OpenProcess(int pId)
        {
            handle = NativeMethods.OpenProcess(NativeMethods.PROCESS_VM_READ | NativeMethods.PROCESS_VM_WRITE | NativeMethods.PROCESS_VM_OPERATION, false, pId);
            return handle;
        }

        public static IntPtr GetHandle()
        {
            return handle;
        }

        /// <summary>
        /// Release / invalidate handle.
        /// </summary>
        public static void CloseProcess()
        {
            NativeMethods.CloseHandle(handle);
        }


        public static bool GetProcessesByName(string pName, out Process process)
        {
            Process[] pList = Process.GetProcessesByName(pName);
            process = pList.Length > 0 ? pList[0] : null;
            return process != null;
        }

        public static bool IsProcessRunning(Process process)
        {
            foreach (Process p in Process.GetProcesses())
            {
                if (p.ProcessName == process.ProcessName)
                    return true;
            }
            return false;
        }



        #region read/write
        /// <summary>
        /// Write genertic type into memory at address.
        /// </summary>
        /// <returns>write succeeded</returns>
        public static bool Write<T>(long address, T t)
        {
            //create byte array with size of type
            byte[] buffer = new byte[Marshal.SizeOf(typeof(T))];

            //allocate handle for buffer
            GCHandle gHandle = GCHandle.Alloc(t, GCHandleType.Pinned);
            //arrange data from unmanaged block of memory to structure of type T
            Marshal.Copy(gHandle.AddrOfPinnedObject(), buffer, 0, buffer.Length);
            gHandle.Free(); //release handle

            //change access permission so we can write into memory
            uint oldProtect;
            NativeMethods.VirtualProtectEx(handle, (IntPtr)address, (uint)buffer.Length, NativeMethods.PAGE_READWRITE, out oldProtect);

            //write buffer into memory
            IntPtr ptrBytesWritten;
            return NativeMethods.WriteProcessMemory(handle, address, buffer, (uint)buffer.Length, out ptrBytesWritten);
        }

        /// <summary>
        /// Reads memory of generic type at address.
        /// </summary>
        public static T Read<T>(long address)
        {
            //create byte array with size of type
            byte[] buffer = new byte[Marshal.SizeOf(typeof(T))];

            //read memory
            UIntPtr bytesRead;
            NativeMethods.ReadProcessMemory(handle, (IntPtr)address, buffer, (UIntPtr)buffer.Length, out bytesRead);

            //allocate handle for buffer
            GCHandle gHandle = GCHandle.Alloc(buffer, GCHandleType.Pinned);//TODO: this line is crashing in Release but not Debug compile. why? AccessViolationException
            //arrange data from unmanaged block of memory to structure of type T
            T data = (T)Marshal.PtrToStructure(gHandle.AddrOfPinnedObject(), typeof(T));
            gHandle.Free(); //release handle

            return data;
        }

        public static string ReadString(long baseAddress, ulong size)
        {
            //create buffer for string
            byte[] buffer = new byte[size];

            //read memory into buffer
            UIntPtr bytesRead;
            NativeMethods.ReadProcessMemory(handle, (IntPtr)baseAddress, buffer, (UIntPtr)buffer.Length, out bytesRead);

            //encode bytes to ascii
            for (int i = 0; i < buffer.Length; i++)
            {
                if (buffer[i] == 0)
                {
                    byte[] tmpBuffer = new byte[i];
                    Buffer.BlockCopy(buffer, 0, tmpBuffer, 0, i);
                    return Encoding.ASCII.GetString(tmpBuffer);
                }
            }
            return Encoding.ASCII.GetString(buffer);
        }

        public static string ReadString2(long baseAddress, ulong size)
        {
            //create buffer for string
            byte[] buffer = new byte[size];

            //read memory into buffer
            UIntPtr bytesRead;
            NativeMethods.ReadProcessMemory(handle, (IntPtr)baseAddress, buffer, (UIntPtr)buffer.Length, out bytesRead);

            //encode bytes to ASCII
            return Encoding.ASCII.GetString(buffer);
        }

        public static bool IsValid(long address)
        {
            return (address >= 0x10000 && address < 0x000F000000000000);
        }
        #endregion
    }
}

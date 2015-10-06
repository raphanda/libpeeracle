package org.peeracle.PeeracleDemo;

import android.content.res.Resources;
import android.os.Environment;
import android.util.Log;

import org.peeracle.DataStream;
import org.peeracle.WebSocketsClient;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.nio.channels.FileChannel;
import java.util.Arrays;

public class FileDataStream extends DataStream {
    private RandomAccessFile file;

    public FileDataStream(File f) {
        super();

        try {
            file = new RandomAccessFile(f, "rw");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public long length() {
        long pos;
        try {
            pos = file.length();
        } catch (IOException e) {
            e.printStackTrace();
            return -1;
        }
        return pos;
    }

    @Override
    public long seek(long position) {
        long pos;
        try {
            file.seek(position);
            pos = file.getFilePointer();
        } catch (IOException e) {
            e.printStackTrace();
            return -1;
        }
        return pos;
    }

    @Override
    public long tell() {
        long pos;
        try {
            pos = file.getFilePointer();
        } catch (IOException e) {
            e.printStackTrace();
            return -1;
        }
        return pos;
    }

    @Override
    public byte[] read(long length) {
        //System.out.println("read " + length + " bytes");
        byte[] result = new byte[(int)length];
        try {
            if (file.getFilePointer() + length > file.length()) {
                return null;
            }
            file.read(result, 0, (int)length);
        } catch (IOException e) {
            e.printStackTrace();
            result = null;
        }

        return result;
    }

    @Override
    public byte[] peek(byte[] buffer, long length) {
        try {
            if (file.getFilePointer() + length > file.length()) {
                return null;
            }
            file.readFully(buffer, (int) file.getFilePointer(), (int) length);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }

        return buffer;
    }

    @Override
    public long write(byte[] buffer, long length) {
        return 0;
    }
}

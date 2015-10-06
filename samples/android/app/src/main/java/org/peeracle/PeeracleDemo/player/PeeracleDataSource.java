package org.peeracle.PeeracleDemo.player;

import android.content.Context;
import android.os.Environment;

import com.google.android.exoplayer.upstream.DataSource;
import com.google.android.exoplayer.upstream.DataSpec;
import com.google.android.exoplayer.upstream.DefaultBandwidthMeter;

import org.peeracle.Metadata;
import org.peeracle.MetadataStream;
import org.peeracle.Session;
import org.peeracle.SessionHandle;
import org.peeracle.PeeracleDemo.FileDataStream;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by marie on 9/14/15.
 */
public class PeeracleDataSource implements DataSource {
    FileDataStream fileDataStream;
    Metadata m;
    byte initSegment[];
    int of = 0;

    public PeeracleDataSource(Context context, DefaultBandwidthMeter bandwidthMeter, String userAgent) {
    }

    private class MySessionObserver implements Session.Observer {
    }

    private class MySessionHandleObserver implements SessionHandle.Observer {
    }

    @Override
    public long open(DataSpec dataSpec) throws IOException {
        File f = new File(Environment.getExternalStorageDirectory() + "/Documents", dataSpec.uri.getPath());
        fileDataStream = new FileDataStream(f);
        m = new Metadata();
        m.unserialize(fileDataStream);

        String id = m.getId();
        ArrayList<String> astr = m.getTrackerUrls();
        ArrayList<MetadataStream> mstr = m.getStreams();

        initSegment = mstr.get(0).getInitSegment();

        //final MySessionObserver sessObserver = new MySessionObserver();
        //Session sess = new Session(sessObserver);

        //final MySessionHandleObserver sessHandleObserver = new MySessionHandleObserver();
        //SessionHandle handle = sess.addMetadata(m, sessHandleObserver);
        return mstr.get(0).getInitSegmentLength();
    }

    @Override
    public void close() throws IOException {

    }

    @Override
    public int read(byte[] bytes, int offset, int length) throws IOException {
        if (of >= initSegment.length) {
            return 0;
        }
        System.arraycopy(initSegment, of, bytes, offset,length);
        of += length;
        return length;
    }
}

package cookbook.chapter8.portingwithbuildsystem;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class MainActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        naCreateABmp(400, 400, 24);
    }

    private static native void naCreateABmp(int width, int height, int depth);
    
    static {
        System.loadLibrary("PortingWithBuildSystem");
    }
}

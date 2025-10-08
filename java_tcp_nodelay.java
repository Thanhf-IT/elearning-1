// java_tcp_nodelay.java
// Compile: javac java_tcp_nodelay.java
// Run: java java_tcp_nodelay
import java.net.*;
import java.io.*;

public class java_tcp_nodelay {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("127.0.0.1", 9000);
        System.out.println("TCP_NODELAY before: " + s.getTcpNoDelay());
        s.setTcpNoDelay(true);
        System.out.println("TCP_NODELAY after: " + s.getTcpNoDelay());
        OutputStream out = s.getOutputStream();
        out.write("hello from java\n".getBytes());
        out.flush();
        s.close();
    }
}

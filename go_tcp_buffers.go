// go_tcp_buffers.go
// go run go_tcp_buffers.go
package main
import (
    "net"
    "fmt"
    "time"
)
func main() {
    conn, err := net.Dial("tcp", "127.0.0.1:9000")
    if err != nil { panic(err) }
    tcp := conn.(*net.TCPConn)
    // Set TCP NoDelay (disable Nagle)
    tcp.SetNoDelay(true)
    // Set read/write buffer sizes
    tcp.SetReadBuffer(256*1024)
    tcp.SetWriteBuffer(256*1024)
    fmt.Println("Configured TCP options on connection")
    tcp.Write([]byte("hello from go\n"))
    time.Sleep(time.Second)
    tcp.Close()
}

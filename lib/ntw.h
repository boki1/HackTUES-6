namespace ntw
{

    class NetworkManager {
    public:

        // Both accept a buffer - to read from or to write in
        // and return an integer - the number of bytes written/read
        // from the number.
       int Receive(char *buf);
       int Transmit(char *buf);

       // A wrapper functions of the above.
       int ReceiveBlock(char *buf);
       int TransmitBlock(char *buf);

    };

}
#pragma once

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#if !defined (PLAYFAB_PLATFORM_PLAYSTATION)
#include <netdb.h>
#endif
constexpr int SOCKET_ERROR = -1;
constexpr int WSAEWOULDBLOCK = 10035;
#endif

namespace PlayFabInternal
{
    namespace QoS
    {
        /// <summary>
        /// A cross-platform implementation of a network socket.
        /// </summary>
        class XPlatSocket
        {
        public:
            XPlatSocket();
            ~XPlatSocket();

            XPlatSocket(const XPlatSocket&) = delete;
            XPlatSocket(XPlatSocket&&) = delete;
            XPlatSocket& operator=(const XPlatSocket&) = delete;
            XPlatSocket& operator=(XPlatSocket&&) = delete;

            // Initialize the socket class. Needs to be called before any other function can be called.
            int InitializeSocket();

            // Set the address the socket would ping
            int SetAddress(const char* socketAddr);

            // Set the port the socket would ping
            int SetPort(int port);

            // Set the timeout for an individual socket call
            int SetTimeout(int timeout);

            // Send the message and return the error code
            int SendMessage(const char* message);

            // Receive the reply and return the error code
            int ReceiveReply(char* buf, const int& buflen);

            // Get the last error code
            int GetLastErrorCode();

        private:
            // Log if the socket was not initialized.
            // If we logged, will return true, else will return false.
            bool LogErrorIfNotInitialized();

        private:
            bool initialized;
            struct sockaddr_in siOther;

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            int s, slen;
            WSADATA wsa;
#elif defined(PLAYFAB_PLATFORM_ANDROID)
            unsigned int s;
            socklen_t slen;
#else
            unsigned int s, slen;
#endif
        };
    }
}
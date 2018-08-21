# CGI (Common Gateway Interface)
外部应用程序与 WEB 服务器之间的接口标准

## 运行原理
* 当用户访问我们的 Web 应用时，会发起一个 HTTP 请求。最终 Web 服务器接收到这个请求。
* Web 服务器创建一个新的 CGI 进程。在这个进程中，将 HTTP 请求数据已一定格式解析出来，并通过标准输入和环境变量传入到 URL 指定的 CGI 程序（PHP 应用 $\_SERVER)
* Web 应用程序处理完成后将返回数据写入到标准输出中，Web 服务器进程则从标准输出流中读取到响应，并采用 HTTP 协议返回给用户响应。

# FastCGI 常驻型 CGI 协议

## 运行原理
* FastCGI 进程管理器启动时会创建一个 主（Master） 进程和多个 CGI 解释器进程（Worker 进程），然后等待 Web 服务器的连接。
* Web 服务器接收 HTTP 请求后，将 CGI 报文通过 套接字（UNIX 或 TCP Socket）进行通信，将环境变量和请求数据写入标准输入,转发到 CGI 解释器进程。
* CGI 解释器进程完成处理后将标准输出和错误信息从同一连接返回给 Web 服务器。
* CGI 解释器进程等待下一个 HTTP 请求的到来。

## web 服务器和 FastCGI 交互过程
* Web 服务器接收用户请求，但最终处理请求由 Web 应用完成。此时，Web 服务器尝试通过套接字（UNIX 或 TCP 套接字，具体使用哪个由 Web 服务器配置决定）连接到 FastCGI 进程。
* FastCGI 进程查看接收到的连接。选择「接收」或「拒绝」连接。如果是「接收」连接，则从标准输入流中读取数据包。
* 如果 FastCGI 进程在指定时间内没有成功接收到连接，则该请求失败。否则，Web 服务器发送一个包含唯一的 RequestID 的 BEGIN_REQUEST 类型消息给到 FastCGI 进程。后续所有数据包发送都包含这个 RequestID。 然后，Web 服务器发送任意数量的 PARAMS 类型消息到 FastCGI 进程。一旦发送完毕，Web 服务器通过发送一个空 PARAMS 消息包，然后关闭这个流。 另外，如果用户发送了 POST 数据 Web 服务器会将其写入到 标准输入（STDIN） 发送给 FastCGI 进程。当所有 POST 数据发送完成，会发送一个空的 标准输入（STDIN） 来关闭这个流。
* 同时，FastCGI 进程接收到 BEGIN_REQUEST 类型数据包。它可以通过响应 END_REQUEST 来拒绝这个请求。或者接收并处理这个请求。如果接收请求，FastCGI 进程会等待接收所有的 PARAMS 和 标准输入数据包。 然后，在处理请求并将返回结果写入 标准输出（STDOUT） 流。处理完成后，发送一个空的数据包到标准输出来关闭这个流，并且会发送一个 END_REQUEST 类型消息通知 Web 服务器，告知它是否发生错误异常。

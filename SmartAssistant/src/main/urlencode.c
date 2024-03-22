#include"urlencode.h"
// 请求服务器mp3文件将中文名进行URL编码
// URL编码会将非ASCII字符转换为形如 %XX 的格式，其中 XX 是对应字符的UTF-8编码的每个字节转换为十六进制的结果
String url_encode(const String& str)
{
    String encode_str;
    for (char c:str)
    {
        if((isalnum(c)||c=='-'||c=='_'||c=='~'||c=='//'||c=='/'||c==':'))
        {
            encode_str+=c;
        }
        else
        {
            char buf[4];
            snprintf(buf,sizeof(buf),"%%%02X",static_cast<unsigned char>(c));
            encode_str+=buf;
        }
    }
    return encode_str;
    
}



#include "rpc_stream.h"

//extern Serial pc;

void stream_init()
{

}

char stream_read()
{
    int c = getchar();
    if (c == EOF) return '\r';
    return c;
}

bool stream_write(char c)
{
    return putchar(c);
}

bool stream_write_string(char *str, int len)
{
    for (int i = 0; str[i] && i < len; i++)
    {
        stream_write(str[i]);
    }
}

void writer_print(type_t type, const void *data, bool append_comma)
{
    char buff[32];
    switch (type)
    {
        case TYPE_BOOL:
        case TYPE_UINT8:
            sprintf(buff, "%hhu", *(uint8_t *)data);
            break;
        case TYPE_UINT16:
            sprintf(buff, "%u", *(uint16_t *)data);
            break;
        case TYPE_UINT32:
            sprintf(buff, "%lu", *(uint32_t *)data);
            break;
        case TYPE_INT8:
            sprintf(buff, "%hhd", *(int8_t *)data);
            break;
        case TYPE_INT:
            sprintf(buff, "%d", *(int *)data);
            break;
        case TYPE_INT16:
            sprintf(buff, "%d", *(int16_t *)data);
            break;
        case TYPE_INT32:
            sprintf(buff, "%ld", *(int32_t *)data);
            break;
        case TYPE_FLOAT:
            sprintf(buff, "%f", *(float *)data);
            break;
        case TYPE_STRING:
            stream_write_string((char *)data, 32);
            return;
        default:
            break;
    }
    stream_write_string(buff, 32);
    if(append_comma) stream_write(',');
}

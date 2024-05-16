#include <iostream>
#include <string>
extern "C"
{
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return -1;
    }

    const char *input_file = argv[1];

    AVFormatContext *format_context = avformat_alloc_context();
    if (!format_context)
    {
        std::cerr << "Could not allocate memory for format context" << std::endl;
        return -1;
    }

    if (avformat_open_input(&format_context, input_file, nullptr, nullptr) != 0)
    {
        std::cerr << "file could not be opened'" << input_file << "'" << std::endl;
        avformat_free_context(format_context);
        return -1;
    }

    if (avformat_find_stream_info(format_context, nullptr) < 0)
    {
        std::cerr << "Could not get stream info" << std::endl;
        avformat_close_input(&format_context);
        return -1;
    }

    std::cout << "Количество потоков: " << format_context->nb_streams << std::endl;
    for (int i = 0; i < format_context->nb_streams; i++)
    {
        AVStream *stream = format_context->streams[i];
        AVCodecParameters *codecParams = stream->codecpar;

        if (codecParams->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            // Video Stream
            std::cout << "Видео кодек: " << avcodec_get_name(codecParams->codec_id) << std::endl;
            std::cout << "Количество кадров: " << stream->nb_frames << std::endl;
        }
        else if (codecParams->codec_type == AVMEDIA_TYPE_AUDIO)
        {
            // Audio Stream
            std::cout << "Аудио кодек: " << avcodec_get_name(codecParams->codec_id) << std::endl;
        }
    }

    // Duration in milliseconds
    int64_t duration = format_context->duration / AV_TIME_BASE;
    std::cout << "Продолжительность: " << duration << " сек" << std::endl;

    avformat_close_input(&format_context);
    avformat_free_context(format_context);

    return 0;
}

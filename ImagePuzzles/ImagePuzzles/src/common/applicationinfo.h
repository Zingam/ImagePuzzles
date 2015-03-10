#ifndef APPLICATIONINFO
#define APPLICATIONINFO

struct ApplicationInfo
{
    const char* title;
    const char* author;

    explicit ApplicationInfo(const char* title, const char* author) :
        title(title),
        author(author)
    {}
};

#endif // APPLICATIONINFO


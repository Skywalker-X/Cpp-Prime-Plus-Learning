#include<iostream>
#include<cstring>
using namespace std;

class DMA
{
protected:
    char * label;
    int rating;
public:
    DMA(const char * l="null", int r=0);
    DMA(const DMA & rs);
    virtual ~DMA();
    DMA & operator=(const DMA & rs);
    virtual void View() const = 0;
};

DMA::DMA(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA & rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

DMA::~DMA()
{
    delete [] label;
}

DMA & DMA::operator=(const DMA & rs)
{
    if(this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void DMA::View() const
{
    cout << "Label: " << label << endl;
    cout << "Rating: " << rating << endl;
}






class baseDMA : public DMA
{    
public:
    baseDMA(const char * l="null", int r=0) : DMA(l, r) {}
    baseDMA(const baseDMA & rs) : DMA(rs) {} 
    baseDMA & operator=(const baseDMA & rs);
    virtual void View() const { DMA::View(); }
};

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
        return *this;
    DMA::operator=(rs);
    return *this;
}








class lacksDMA : public DMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c="blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    virtual void View() const;
};

lacksDMA::lacksDMA(const char * c, const char * l, int r) : DMA(l, r)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : DMA(rs)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
    DMA::View();
    cout << "Color: " << color << endl;
}







class hasDMA : public DMA
{
private:
    char * style;
public:
    hasDMA(const char * s="none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    virtual void View() const;
};

hasDMA::hasDMA(const char * s, const char * l, int r) : DMA(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) : DMA(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : DMA(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if(this == &hs)
        return *this;
    DMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const
{
    DMA::View();
    cout << "Style: " << style << endl;
}






int main()
{
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    shirt.View();
    cout << "Displaying lacksDMA object:\n";
    balloon.View();
    cout << "Displaying hasDMA object:\n";
    map.View();
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    balloon2.View();
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    map2.View();
    return 0;
}
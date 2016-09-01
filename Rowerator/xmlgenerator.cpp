#include "xmlgenerator.h"

XmlGenerator::XmlGenerator()
{

}

XmlGenerator::~XmlGenerator()
{
}

void XmlGenerator::set(float *l, qreal *qr)
{
    for(int i = 0; i<8;++i){
        this->length[i] = l[i];
        if(i<4)
            this->angle[i] = qr[i];
    }
}

QString XmlGenerator::generate()
{
    QString result="";
    result += "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<?xml-stylesheet type=\"text/css\" href=\"css.css\"?>\n\
<Rowerator>\n\
\t<Dlugosc>\n\
\t\t<Temat><p>Lista Dlugości</p></Temat>\n\
\t\t\t<Td>Korpus - <span>"+ QString::number(this->length[1]) +"</span></Td>\n\
\t\t\t<Td>Udo - <span>"+ QString::number(this->length[2]) +"</span> </Td>\n\
\t\t\t<Td>Piszczel - <span>"+ QString::number(this->length[3]) +"</span></Td>\n\
\t\t\t<Td>Ramię - <span>"+ QString::number(this->length[4]) +"</span></Td>\n\
\t\t\t<Td>Przedramię - <span>"+ QString::number(this->length[5]) +"</span></Td>\n\
\t\t\t<Td>Dł użytkownika 1 - <span>"+ QString::number(this->length[6]) +"</span></Td>\n\
\t\t\t<Td>Dł użytkownika 2 - <span>"+ QString::number(this->length[7]) +"</span></Td>\n\n\
\t</Dlugosc>\n\n\
\t<Kat>\n\
\t\t<Temat><p>Lista katow</p></Temat>\n\
\t\t\t<Td>Korpus:Udo - <span>"+ QString::number(this->angle[0]) +"</span></Td>\n\
\t\t\t<Td>Udo>Piszczel - <span>"+ QString::number(this->angle[1]) +"</span></Td>\n\
\t\t\t<Td>Ramię:Przedramię - <span>"+ QString::number(this->angle[2]) +"</span></Td>\n\
\t\t\t<Td>Dł uż 1:Dł uż 2 - <span>"+ QString::number(this->angle[3]) +"</span></Td>\n\
\t</Kat>\n\n\
</Rowerator>\n";

    return result;
}

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
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n                                                    \
<?xml-stylesheet type=\"text/css\" href=\"css.css\"?>\n                                         \
<Rowerator>\n                                                                                   \
    <Punkt>                                                                                     \
        <Temat><p>Tutaj są podane Punkty Rowerzysty w orientacji <span>Y:X</span></p></Temat>   \
              <Td>Szyja - <span>60:70 </span></Td>                                              \
              <Td>Łokieć - <span>50:50 </span></Td>                                             \
              <Td>Ręce - <span>40:30</span> </Td>                                               \
              <Td>Biodra - <span>40:70 </span></Td>                                             \
              <Td>Kolano - <span>30:50</span></Td>                                              \
              <Td>Zakończenie nogi - <span>20:60</span></Td>                                    \
              <Td>Pięta - <span>18:60</span></Td>                                               \
              <Td>Palce - <span>15:55</span></Td>                                               \
                                                                                                \
    </Punkt>                                                                                    \
                                                                                                \
    <Kat>                                                                                       \
          <Temat><p>Tutaj są podane Kąty odpowiadające punktom powyżej w ujęciu  <span>procentowym</span></p></Temat>\
              <Td>Łokciowy - <span>5%</span></Td>                                               \
              <Td>Pachowy - <span>30%</span></Td>                                               \
              <Td>Biodrowy - <span>40%</span></Td>                                              \
              <Td>Kolanowy - <span>30%</span></Td>                                              \
              <Td>Stopowy - <span>15%</span></Td>                                               \
    </Kat>                                                                                      \
                                                                                                \
</Rowerator>";

    for(int i = 0; i<8;++i){
        result += QString::number(this->length[i]);
        result += "\n";
    }
    return result;
}

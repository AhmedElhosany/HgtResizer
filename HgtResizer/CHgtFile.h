/*
 *   -------------------------------------------------------------------------
 *    HgtResizer v1.0
 *                                                    (c) Robert Rypula 156520
 *                                   Wroclaw University of Technology - Poland
 *                                                      http://www.pwr.wroc.pl
 *                                                           2011.01 - 2011.06
 *   -------------------------------------------------------------------------
 *
 *   What is this:
 *     - SRTM data resizer from 92.77m to 101.92m grid for more flexible LOD
 *       division in HgtReader program
 *     - html HGT index generator with jpg terrain presentation
 *     - part of my thesis "Rendering of complex 3D scenes"
 *
 *   What it use:
 *     - Nokia Qt cross-platform C++ application framework
 *     - NASA SRTM terrain elevation data:
 *         oryginal dataset
 *           http://dds.cr.usgs.gov/srtm/version2_1/SRTM3/
 *         corrected part of earth:
 *           http://www.viewfinderpanoramas.org/dem3.html
 *         SRTM v4 highest quality SRTM dataset avaiable:
 *           http://srtm.csi.cgiar.org/
 *     - ALGLIB cross-platform numerical analysis and data processing library
 *         ALGLIB website:
 *           http://www.alglib.net/
 *
 *   Contact to author:
 *            phone    +48 505-363-331
 *            e-mail   robert.rypula@gmail.com
 *            GG       1578139
 *
 *                                                   program under GNU licence
 *   -------------------------------------------------------------------------
 */

#ifndef CHGTFILE_H
#define CHGTFILE_H

#include <QString>
#include <fstream>

using namespace std;

class CHgtFile
{
public:
    CHgtFile();
    ~CHgtFile();

    void init(int sX, int sY);
    void saveFile(QString name);
    void loadFile(QString name, int x, int y);
    int getHeight(int x, int y) { return (int)height[y*sizeX + x]; }
    void setHeight(int x, int y, int hgt) { height[y*sizeX + x] = (quint16)hgt; }
    void getHeightBlock(int *buffer, int x, int y, int sx, int sy, int skip);
    void getHeightBlock(quint16 *buffer, int x, int y, int sx, int sy, int skip);
    void setHeightBlock(int *buffer, int x, int y, int sx, int sy, int skip);
    void setHeightBlock(quint16 *buffer, int x, int y, int sx, int sy, int skip);
    void fileOpen(QString name, int sX, int sY);
    void fileClose();
    void fileSetHeight(int x, int y, int hgt);
    int fileGetHeight(int x, int y);
    void fileGetHeightBlock(int *buffer, int x, int y, int sx, int sy, int skip);
    void fileGetHeightBlock(quint16 *buffer, int x, int y, int sx, int sy, int skip);
    void fileSetHeightBlock(int *buffer, int x, int y, int sx, int sy, int skip);
    void fileSetHeightBlock(quint16 *buffer, int x, int y, int sx, int sy, int skip);
    void savePGM(QString name);

private:
    fstream file;
    quint16 *height;
    int sizeX;
    int sizeY;

    void exchangeEndian();
};

#endif // CHGTFILE_H

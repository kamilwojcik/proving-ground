#include "compression.hpp"
#include <iostream>
#include <algorithm>


void printCompressedRow (std::vector<std::pair<uint8_t, uint8_t>> row)
{
    std::cout<<"Compressed row: ";
    std::for_each(begin(row), end(row), [](auto p){std::cout<<"{"<<(int)p.first<<", "<<(int)p.second<<"} ";});
    std::cout<<std::endl;
}

//////////////
// compression
class RowCompressor
{
private:
    uint8_t row_element;
    int counter;
    std::vector<std::pair<uint8_t, uint8_t>> ans;

public:

    RowCompressor(uint8_t first_element)
    {
        row_element = first_element;
        counter = 0;
        ans.reserve(width);
    }

    std::vector<std::pair<uint8_t, uint8_t>> GetCompressedRow()
    {
        ans.emplace_back(row_element, counter);
        ans.shrink_to_fit();
        return ans;
    }

    void operator() (uint8_t next_element)
    {
        if (row_element == next_element) counter++;
        else
        {
            ans.emplace_back(row_element, counter);
            row_element = next_element;
            counter=1;
        }
    }
};

std::vector<std::pair<uint8_t, uint8_t>> compressRow(std::array<uint8_t,width> row)
{
    RowCompressor compressor(row[0]);
    std::for_each(begin(row), end(row), [&compressor](auto i){compressor(i);});
    return compressor.GetCompressedRow();
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> to_compress)
{
    std::vector<std::pair<uint8_t, uint8_t>> ans;
    ans.reserve(width*height);
    
    std::for_each(begin(to_compress), end(to_compress), [&ans](auto& row){
        auto compressed_row = compressRow(row);
        ans.insert(end(ans), begin(compressed_row), end(compressed_row));
    });

    ans.shrink_to_fit();
    return ans;
}

////////////////
// decompression


// class Decompressor
// {
// private:

// };

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> to_decompress)
{
    std::array<std::array<uint8_t, width>, height> ans;
    int row, col, counter=0;

    //std::for_each(begin(to_decompress), end(to_decompress), decompression)

    for (auto& pair : to_decompress)
        for (int i=0; i<pair.second; i++)
        {
            row = counter/height; //only integer part is saved;
            col = counter % width;
            ans[row][col] = pair.first;
            counter++;
        }
    
    return ans;
}

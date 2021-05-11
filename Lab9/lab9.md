1. 
   Four floating point divisions in single precision (i.e. float)
       Answer:__m128 _mm_div_ps (__m128 a, __m128 b)

Sixteen max operations over signed 8-bit integers (i.e. char)
    Answer:__m128i _mm_max_epi8 (__m128i a, __m128i b) 
    Note:It seems that there are only epi16 and epu8 but ont epi8

Arithmetic shift right of eight signed 16-bit integers (i.e. short)
    Answer:__m128i _mm_sra_epi16 (__m128i a, __m128i count),imm8[7:0]
    Or:__m128i _mm_srai_epi16 (__m128i a, int imm8),count[63:0]



2. 
   Loop should be inside L14 since there are only two mul in this .s, and they are all inside L14

Comments seen in that file.






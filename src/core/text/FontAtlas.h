#ifndef SRC_CORE_TEXT_FONTATLAS_H_
#define SRC_CORE_TEXT_FONTATLAS_H_

#include <unordered_map>

#include "GlyphString.h"
#include "core/images/Bitmap.h"
#include "core/math/Rect.h"
#include "core/types.h"
#include "util/include/glm.h"

struct Glyph {
  u32 width;
  u32 height;
  u32 advance;
  glm::vec2 bearing;
  Rectf textureCoordinate;
};

class FontAtlas {
 public:
  static FontAtlas Create();

  u32 GetFontHeight() const;
  const Bitmap& AsImage() const;
  const Glyph& RetrieveGlyph(GlyphCode charCode) const;

 private:
  FontAtlas(u32 fontHeight, Bitmap image,
            std::unordered_map<GlyphCode, Glyph> glyphs);

 private:
  u32 fontHeight_;
  Bitmap image_;
  std::unordered_map<GlyphCode, Glyph> glyphs_;
};

#endif  // SRC_CORE_TEXT_FONTATLAS_H_

//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2022
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "td/telegram/StickerType.h"

namespace td {

StickerType get_sticker_type(const td_api::object_ptr<td_api::StickerType> &type) {
  if (type == nullptr) {
    return StickerType::Regular;
  }
  switch (type->get_id()) {
    case td_api::stickerTypeRegular::ID:
      return StickerType::Regular;
    case td_api::stickerTypeMask::ID:
      return StickerType::Mask;
    case td_api::stickerTypeEmoji::ID:
      return StickerType::Emoji;
    default:
      UNREACHABLE();
      return StickerType::Regular;
  }
}

td_api::object_ptr<td_api::StickerType> get_sticker_type_object(StickerType sticker_type) {
  switch (sticker_type) {
    case StickerType::Regular:
      return td_api::make_object<td_api::stickerTypeRegular>();
    case StickerType::Mask:
      return td_api::make_object<td_api::stickerTypeMask>();
    case StickerType::Emoji:
      return td_api::make_object<td_api::stickerTypeEmoji>();
    default:
      UNREACHABLE();
      return nullptr;
  }
}

StringBuilder &operator<<(StringBuilder &string_builder, StickerType sticker_type) {
  switch (sticker_type) {
    case StickerType::Regular:
      return string_builder << "Regular";
    case StickerType::Mask:
      return string_builder << "Mask";
    case StickerType::Emoji:
      return string_builder << "Emoji";
    default:
      UNREACHABLE();
      return string_builder;
  }
}

}  // namespace td

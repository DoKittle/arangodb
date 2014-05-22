////////////////////////////////////////////////////////////////////////////////
/// @brief collection key generator
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2013 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2012-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_VOC_BASE_KEY_GENERATOR_H
#define TRIAGENS_VOC_BASE_KEY_GENERATOR_H 1

#include "Basics/Common.h"

#include "VocBase/vocbase.h"

// -----------------------------------------------------------------------------
// --SECTION--                                                    KEY GENERATORS
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// --SECTION--                                              FORWARD DECLARATIONS
// -----------------------------------------------------------------------------

struct TRI_json_s;

// -----------------------------------------------------------------------------
// --SECTION--                                                    public defines
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief maximum length of a key in a collection
////////////////////////////////////////////////////////////////////////////////

#define TRI_VOC_KEY_MAX_LENGTH (254)

// -----------------------------------------------------------------------------
// --SECTION--                                                      public types
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief general key generator type
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_key_generator_s {
  void* _data;
  
  int (*init)(struct TRI_key_generator_s*, struct TRI_json_s const*);
  std::string (*generateKey)(struct TRI_key_generator_s*, TRI_voc_tick_t);
  int (*validateKey)(struct TRI_key_generator_s const*, std::string const&);
  void (*trackKey)(struct TRI_key_generator_s*, TRI_voc_key_t);
  void (*free)(struct TRI_key_generator_s*);
  struct TRI_json_s* (*toJson)(struct TRI_key_generator_s const*);
}
TRI_key_generator_t;

// -----------------------------------------------------------------------------
// --SECTION--                                        constructors / destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief create a key generator
////////////////////////////////////////////////////////////////////////////////

int TRI_CreateKeyGenerator (struct TRI_json_s const*,
                            struct TRI_key_generator_s**);

////////////////////////////////////////////////////////////////////////////////
/// @brief free a key generator
////////////////////////////////////////////////////////////////////////////////

void TRI_FreeKeyGenerator (TRI_key_generator_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief validate a key
////////////////////////////////////////////////////////////////////////////////

bool TRI_ValidateKeyKeyGenerator (char const*);

////////////////////////////////////////////////////////////////////////////////
/// @brief validate a document id (collection name + / + document key)
////////////////////////////////////////////////////////////////////////////////

bool TRI_ValidateDocumentIdKeyGenerator (char const*,
                                         size_t*);

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|/// @page\\|// --SECTION--\\|/// @\\}"

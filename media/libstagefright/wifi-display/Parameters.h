/*
 * Copyright 2012-2021, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <media/stagefright/foundation/ABase.h>
#include <media/stagefright/foundation/AString.h>
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>

namespace android {

struct Parameters : public RefBase {
    static sp<Parameters> Parse(const char *data, size_t size);

    bool findParameter(const char *name, AString *value) const;

protected:
    virtual ~Parameters();

private:
    KeyedVector<AString, AString> mDict;

    Parameters();
    status_t parse(const char *data, size_t size);

    DISALLOW_EVIL_CONSTRUCTORS(Parameters);
};

}  // namespace android

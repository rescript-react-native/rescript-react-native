

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_mapperRt from "bs-platform/lib/es6/js_mapperRt.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function jsSectionToSection(jsSection) {
  return /* record */[
          /* data */jsSection.data,
          /* key */Caml_option.undefined_to_opt(jsSection.key),
          /* renderItem */undefined
        ];
}

function renderItem(reRenderItem, jsRenderBag) {
  return Curry._1(reRenderItem, /* record */[
              /* item */jsRenderBag.item,
              /* index */jsRenderBag.index,
              /* section */jsSectionToSection(jsRenderBag.section),
              /* separators */jsRenderBag.separators
            ]);
}

function section(data, key, renderItem, param) {
  return /* record */[
          /* data */data,
          /* key */key,
          /* renderItem */renderItem
        ];
}

function sections(reSections) {
  return $$Array.map((function (reSection) {
                return {
                        data: reSection[/* data */0],
                        key: Js_undefined.fromOption(reSection[/* key */1]),
                        renderItem: Js_undefined.fromOption(Belt_Option.map(reSection[/* renderItem */2], renderItem))
                      };
              }), reSections);
}

function separatorComponent(reSeparatorComponent, jsSeparatorProps) {
  return Curry._1(reSeparatorComponent, /* record */[
              /* highlighted */jsSeparatorProps.highlighted,
              /* leadingItem */Caml_option.undefined_to_opt(jsSeparatorProps.leadingItem),
              /* leadingSection */Belt_Option.map(Caml_option.undefined_to_opt(jsSeparatorProps.leadingSection), jsSectionToSection),
              /* section */jsSectionToSection(jsSeparatorProps.section),
              /* trailingItem */Caml_option.undefined_to_opt(jsSeparatorProps.trailingItem),
              /* trailingSection */Belt_Option.map(Caml_option.undefined_to_opt(jsSeparatorProps.trailingSection), jsSectionToSection)
            ]);
}

function renderAccessoryView(reRenderAccessory, jsRenderAccessory) {
  return Curry._1(reRenderAccessory, /* record */[/* section */jsSectionToSection(jsRenderAccessory.section)]);
}

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -922086728,
    "none"
  ],
  /* tuple */[
    -453364557,
    "onDrag"
  ],
  /* tuple */[
    1012481506,
    "interactive"
  ]
];

function keyboardDismissModeToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    -975851588,
    "handled"
  ],
  /* tuple */[
    -958984497,
    "always"
  ],
  /* tuple */[
    422592140,
    "never"
  ]
];

function keyboardShouldPersistTapsToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$1);
}

function make(sections, renderItem, keyExtractor, itemSeparatorComponent, listEmptyComponent, listFooterComponent, listHeaderComponent, sectionSeparatorComponent, inverted, extraData, initialNumToRender, onEndReached, onEndReachedThreshold, onViewableItemsChanged, onRefresh, refreshing, renderSectionHeader, renderSectionFooter, stickySectionHeadersEnabled, keyboardDismissMode, keyboardShouldPersistTaps, showsHorizontalScrollIndicator, showsVerticalScrollIndicator, getItemLayout, _children) {
  return ReasonReact.wrapJsForReason(ReactNative.SectionList, {
              sections: sections,
              renderItem: renderItem,
              keyExtractor: keyExtractor,
              ItemSeparatorComponent: itemSeparatorComponent,
              ListEmptyComponent: listEmptyComponent,
              ListFooterComponent: listFooterComponent,
              ListHeaderComponent: listHeaderComponent,
              SectionSeparatorComponent: sectionSeparatorComponent,
              inverted: inverted,
              extraData: extraData,
              initialNumToRender: initialNumToRender,
              onEndReached: onEndReached,
              onEndReachedThreshold: onEndReachedThreshold,
              onRefresh: onRefresh,
              onViewableItemsChanged: onViewableItemsChanged,
              refreshing: refreshing,
              renderSectionHeader: renderSectionHeader,
              renderSectionFooter: renderSectionFooter,
              stickySectionHeadersEnabled: stickySectionHeadersEnabled,
              keyboardDismissMode: Belt_Option.map(keyboardDismissMode, keyboardDismissModeToJs),
              keyboardShouldPersistTaps: Belt_Option.map(keyboardShouldPersistTaps, keyboardShouldPersistTapsToJs),
              showsHorizontalScrollIndicator: showsHorizontalScrollIndicator,
              showsVerticalScrollIndicator: showsVerticalScrollIndicator,
              getItemLayout: Belt_Option.map(getItemLayout, (function (f, data, index) {
                      return Curry._2(f, data === undefined ? undefined : Caml_option.some(data), index);
                    }))
            }, _children);
}

export {
  section ,
  sections ,
  renderItem ,
  separatorComponent ,
  renderAccessoryView ,
  make ,
  
}
/* ReasonReact Not a pure module */

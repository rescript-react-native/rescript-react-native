open Utils;

external view : ReactRe.reactClass = "ScrollView" [@@bs.module "react-native"];

type point = {x: float, y: float};

external _scrollTo : ReactRe.reactRef => Js.t {. x : int, y : int, animated : Js.boolean} => unit =
  "scrollTo" [@@bs.send];

external _scrollToEnd : ReactRe.reactRef => Js.t {. animated : Js.boolean} => unit =
  "scrollToEnd" [@@bs.send];

let scrollTo ref ::x ::y ::animated => _scrollTo ref {"x": x, "y": y, "animated": to_js_boolean animated};

let scrollToEnd ref ::animated => _scrollToEnd ref {"animated": to_js_boolean animated};

let createElement
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::onMoveShouldSetResponder=?
    ::onMoveShouldSetResponderCapture=?
    ::onResponderGrant=?
    ::onResponderMove=?
    ::onResponderReject=?
    ::onResponderRelease=?
    ::onResponderTerminate=?
    ::onResponderTerminationRequest=?
    ::onStartShouldSetResponder=?
    ::onStartShouldSetResponderCapture=?
    ::pointerEvents=?
    ::removeClippedSubviews=?
    ::style=?
    ::testID=?
    ::accessibilityComponentType=?
    ::accessibilityLiveRegion=?
    ::collapsable=?
    ::importantForAccessibility=?
    ::needsOffscreenAlphaCompositing=?
    ::renderToHardwareTextureAndroid=?
    ::accessibilityTraits=?
    ::accessibilityViewIsModal=?
    ::shouldRasterizeIOS=?
    ::contentContainerStyle=?
    ::horizontal=?
    ::keyboardDismissMode=?
    ::keyboardShouldPersistTaps=?
    ::onContentSizeChange=?
    ::onScroll=?
    ::pagingEnabled=?
    ::refreshControl=?
    ::scrollEnabled=?
    ::showsHorizontalScrollIndicator=?
    ::showsVerticalScrollIndicator=?
    ::stickyHeaderIndices=?
    ::overScrollMode=?
    ::scrollPerfTag=?
    ::alwaysBounceHorizontal=?
    ::alwaysBounceVertical=?
    ::automaticallyAdjustContentInsets=?
    ::bounces=?
    ::canCancelContentTouches=?
    ::centerContent=?
    ::contentInset=?
    ::contentOffset=?
    ::decelerationRate=?
    ::directionalLockEnabled=?
    ::indicatorStyle=?
    ::maximumZoomScale=?
    ::mimimumZoomScale=?
    ::onScrollAnimationEnd=?
    ::scrollEventThrottle=?
    ::scrollIndicatorInsets=?
    ::scrollsToTop=?
    ::snapToAlignment=?
    ::zoomScale=? =>
  ReactRe.wrapPropsShamelessly
    view
    {
      "accessibleLeft": from_opt accessibleLeft,
      "accessible": from_opt (option_map to_js_boolean accessible),
      "hitSlop": from_opt hitSlop,
      "onAccessibilityTap": from_opt onAccessibilityTap,
      "onLayout": from_opt onLayout,
      "onMagicTap": from_opt onMagicTap,
      "onMoveShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponder),
      "onMoveShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onMoveShouldSetResponderCapture),
      "onResponderGrant": from_opt onResponderGrant,
      "onResponderMove": from_opt onResponderMove,
      "onResponderReject": from_opt onResponderReject,
      "onResponderRelease": from_opt onResponderRelease,
      "onResponderTerminate": from_opt onResponderTerminate,
      "onResponderTerminationRequest": from_opt onResponderTerminationRequest,
      "onStartShouldSetResponder":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponder),
      "onStartShouldSetResponderCapture":
        from_opt (option_map ((<<) to_js_boolean) onStartShouldSetResponderCapture),
      "removeClippedSubviews": from_opt (option_map to_js_boolean removeClippedSubviews),
      "pointerEvents":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `auto => "auto"
                | `none => "none"
                | `boxNone => "box-none"
                | `boxOnly => "box-only"
                }
            )
            pointerEvents
        ),
      "style": from_opt style,
      "testID": from_opt testID,
      "accessibilityComponentType":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `none => "none"
                | `button => "button"
                | `radiobutton_checked => "radiobutton_checked-none"
                | `radiobutton_unchecked => "radiobutton_unchecked"
                }
            )
            accessibilityComponentType
        ),
      "accessibilityLiveRegion":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `polite => "polite"
                | `none => "none"
                | `assertive => "assertive"
                }
            )
            accessibilityLiveRegion
        ),
      "collapsable": from_opt (option_map to_js_boolean collapsable),
      "importantForAccessibility":
        from_opt (
          option_map
            (
              fun prop =>
                switch prop {
                | `auto => "auto"
                | `yes => "yes"
                | `no => "no"
                | `noHideDescendants => "noHideDescendants"
                }
            )
            importantForAccessibility
        ),
      "needsOffscreenAlphaCompositing":
        from_opt (option_map to_js_boolean needsOffscreenAlphaCompositing),
      "renderToHardwareTextureAndroid":
        from_opt (option_map to_js_boolean renderToHardwareTextureAndroid),
      "accessibilityTraits":
        from_opt (
          option_map
            (
              fun traits => {
                let to_string =
                  fun
                  | `none => "none"
                  | `button => "button"
                  | `link => "link"
                  | `header => "header"
                  | `search => "search"
                  | `image => "image"
                  | `selected => "selected"
                  | `plays => "plays"
                  | `key => "key"
                  | `text => "text"
                  | `summary => "summary"
                  | `disabled => "disabled"
                  | `frequentUpdates => "frequentUpdates"
                  | `startsMedia => "startsMedia"
                  | `adjustable => "adjustable"
                  | `allowsDirectInteraction => "allowsDirectInteraction"
                  | `pageTurn => "pageTurn";
                traits |> List.map to_string |> Array.of_list
              }
            )
            accessibilityTraits
        ),
      "accessibilityViewIsModal": from_opt (option_map to_js_boolean accessibilityViewIsModal),
      "shouldRasterizeIOS": from_opt (option_map to_js_boolean shouldRasterizeIOS),
      "contentContainerStyle": from_opt contentContainerStyle,
      "horizontal": from_opt (option_map to_js_boolean horizontal),
      "keyboardDismissMode":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `interactive => "interactive"
                | `none => "none"
                | `onDrag => "on-drag"
                }
            )
            keyboardDismissMode
        ),
      "keyboardShouldPersistTaps":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `always => "always"
                | `never => "never"
                | `handled => "handled"
                }
            )
            keyboardShouldPersistTaps
        ),
      "onContentSizeChange": from_opt onContentSizeChange,
      "onScroll": from_opt onScroll,
      "pagingEnabled": from_opt (option_map to_js_boolean pagingEnabled),
      "refreshControl": from_opt refreshControl,
      "scrollEnabled": from_opt (option_map to_js_boolean scrollEnabled),
      "showsHorizontalScrollIndicator":
        from_opt (option_map to_js_boolean showsHorizontalScrollIndicator),
      "showsVerticalScrollIndicator":
        from_opt (option_map to_js_boolean showsVerticalScrollIndicator),
      "stickyHeaderIndices": from_opt (option_map Array.of_list stickyHeaderIndices),
      "overScrollMode":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `always => "always"
                | `never => "never"
                | `auto => "auto"
                }
            )
            overScrollMode
        ),
      "scrollPerfTag": from_opt scrollPerfTag,
      "alwaysBounceHorizontal": from_opt (option_map to_js_boolean alwaysBounceHorizontal),
      "alwaysBounceVertical": from_opt (option_map to_js_boolean alwaysBounceVertical),
      "automaticallyAdjustContentInsets":
        from_opt (option_map to_js_boolean automaticallyAdjustContentInsets),
      "bounces": from_opt (option_map to_js_boolean bounces),
      "canCancelContentTouches": from_opt (option_map to_js_boolean canCancelContentTouches),
      "centerContent": from_opt (option_map to_js_boolean centerContent),
      "contentInset": from_opt contentInset,
      "contentOffset": from_opt (option_map (fun {x, y} => {"x": x, "y": y}) contentOffset),
      "decelerationRate":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `fast => "fast"
                | `normal => "normal"
                }
            )
            decelerationRate
        ),
      "directionalLockEnabled": from_opt (option_map to_js_boolean directionalLockEnabled),
      "indicatorStyle":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `default => "default"
                | `black => "black"
                | `white => "white"
                }
            )
            indicatorStyle
        ),
      "maximumZoomScale": from_opt maximumZoomScale,
      "mimimumZoomScale": from_opt mimimumZoomScale,
      "onScrollAnimationEnd": from_opt onScrollAnimationEnd,
      "scrollEventThrottle": from_opt scrollEventThrottle,
      "scrollIndicatorInsets": from_opt scrollIndicatorInsets,
      "scrollsToTop": from_opt (option_map to_js_boolean scrollsToTop),
      "snapToAlignment":
        from_opt (
          option_map
            (
              fun x =>
                switch x {
                | `center => "center"
                | `start => "start"
                | `end_ => "end"
                }
            )
            snapToAlignment
        ),
      "zoomScale": from_opt zoomScale
    };
external view : ReactRe.reactClass = "ScrollView" [@@bs.module "react-native"];

type point = {x: float, y: float};

external _scrollTo : ReactRe.reactRef => Js.t {. x : int, y : int, animated : Js.boolean} => unit =
  "scrollTo" [@@bs.send];

external _scrollToEnd : ReactRe.reactRef => Js.t {. animated : Js.boolean} => unit =
  "scrollToEnd" [@@bs.send];

let scrollTo ref ::x ::y ::animated =>
  _scrollTo ref {"x": x, "y": y, "animated": Js.Boolean.to_js_boolean animated};

let scrollToEnd ref ::animated => _scrollToEnd ref {"animated": Js.Boolean.to_js_boolean animated};

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
    (
      Props.extendView
        Js.Undefined.(
          {
            "contentContainerStyle": from_opt contentContainerStyle,
            "horizontal": from_opt (Utils.optBoolToOptJsBoolean horizontal),
            "keyboardDismissMode":
              from_opt (
                Utils.option_map
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
                Utils.option_map
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
            "pagingEnabled": from_opt (Utils.optBoolToOptJsBoolean pagingEnabled),
            "refreshControl": from_opt refreshControl,
            "scrollEnabled": from_opt (Utils.optBoolToOptJsBoolean scrollEnabled),
            "showsHorizontalScrollIndicator":
              from_opt (Utils.optBoolToOptJsBoolean showsHorizontalScrollIndicator),
            "showsVerticalScrollIndicator":
              from_opt (Utils.optBoolToOptJsBoolean showsVerticalScrollIndicator),
            "stickyHeaderIndices": from_opt (Utils.option_map Array.of_list stickyHeaderIndices),
            "overScrollMode":
              from_opt (
                Utils.option_map
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
            "alwaysBounceHorizontal": from_opt (Utils.optBoolToOptJsBoolean alwaysBounceHorizontal),
            "alwaysBounceVertical": from_opt (Utils.optBoolToOptJsBoolean alwaysBounceVertical),
            "automaticallyAdjustContentInsets":
              from_opt (Utils.optBoolToOptJsBoolean automaticallyAdjustContentInsets),
            "bounces": from_opt (Utils.optBoolToOptJsBoolean bounces),
            "canCancelContentTouches":
              from_opt (Utils.optBoolToOptJsBoolean canCancelContentTouches),
            "centerContent": from_opt (Utils.optBoolToOptJsBoolean centerContent),
            "contentInset": from_opt contentInset,
            "contentOffset":
              from_opt (Utils.option_map (fun {x, y} => {"x": x, "y": y}) contentOffset),
            "decelerationRate":
              from_opt (
                Utils.option_map
                  (
                    fun x =>
                      switch x {
                      | `fast => "fast"
                      | `normal => "normal"
                      }
                  )
                  decelerationRate
              ),
            "directionalLockEnabled": from_opt (Utils.optBoolToOptJsBoolean directionalLockEnabled),
            "indicatorStyle":
              from_opt (
                Utils.option_map
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
            "scrollsToTop": from_opt (Utils.optBoolToOptJsBoolean scrollsToTop),
            "snapToAlignment":
              from_opt (
                Utils.option_map
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
          }
        )
        ::accessibleLeft
        ::accessible
        ::hitSlop
        ::onAccessibilityTap
        ::onLayout
        ::onMagicTap
        ::onMoveShouldSetResponder
        ::onMoveShouldSetResponderCapture
        ::onResponderGrant
        ::onResponderMove
        ::onResponderReject
        ::onResponderRelease
        ::onResponderTerminate
        ::onResponderTerminationRequest
        ::onStartShouldSetResponder
        ::onStartShouldSetResponderCapture
        ::pointerEvents
        ::removeClippedSubviews
        ::style
        ::testID
        ::accessibilityComponentType
        ::accessibilityLiveRegion
        ::collapsable
        ::importantForAccessibility
        ::needsOffscreenAlphaCompositing
        ::renderToHardwareTextureAndroid
        ::accessibilityTraits
        ::accessibilityViewIsModal
        ::shouldRasterizeIOS
    );
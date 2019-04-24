let make = {
  let textInputRef = React.useRef(Js.Nullable.null);
  let clearText =
    React.useCallback(_ =>
      switch (textInputRef->React.Ref.current->Js.Nullable.toOption) {
      | Some(element) =>
        element->TextInput.setNativeProps({"test": 42});
        element->TextInput.focus;
      | None => ()
      }
    );

  <View>
    <TextInput ref=textInputRef />
    <TouchableOpacity onPress=clearText>
      <Text> "Clear text"->React.string </Text>
    </TouchableOpacity>
  </View>;
};

open ReactNative;

let onButtonPress () => Alert.alert title::"Button has been pressed!" ();

let displayName = "ButtonExample";

let title = "<Button>";

let description = "Simple React Native button component.";

let examples: list Example.t = [
  {
    title: "Simple Button",
    description:
      Some "The title and onPress handler are required. It is recommended to set accessibilityLabel to help make your app usable by everyone.",
    render: fun () =>
      <Button
        onPress=onButtonPress
        title="Press Me"
        accessibilityLabel="See an informative alert"
      />
  },
  {
    title: "Adjusted color",
    description:
      Some (
        "Adjusts the color in a way that looks standard on each " ^
        "platform. On iOS, the color prop controls the color of the text. On " ^ "Android, the color adjusts the background color of the button."
      ),
    render: fun () =>
      <Button
        onPress=onButtonPress
        title="Press Purple"
        color="#841584"
        accessibilityLabel="Learn more about purple"
      />
  },
  {
    title: "Fit to text layout",
    description: Some ("This layout strategy lets the title define the width of " ^ "the button"),
    render: fun () =>
      <View style=Style.(style [flexDirection `row, justifyContent `spaceBetween])>
        <Button
          onPress=onButtonPress
          title="This looks great!"
          accessibilityLabel="This sounds great!"
        />
        <Button
          onPress=onButtonPress
          title="Ok!"
          color="#841584"
          accessibilityLabel="Ok, Great!"
        />
      </View>
  },
  {
    title: "Disabled Button",
    description: Some "All interactions for the component are disabled.",
    render: fun () =>
      <Button
        disabled=true
        onPress=onButtonPress
        title="I Am Disabled"
        accessibilityLabel="See an informative alert"
      />
  }
];
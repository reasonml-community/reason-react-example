let component = ReasonReact.createComponent "PageReason";

let make ::message ::extraGreeting=? _children => {
  ...component,
  render: fun () _self => {
    let greeting =
      switch extraGreeting {
      | None => "How are you?"
      | Some g => g
      };
    <div> <MyBannerRe show=true message=(message ^ " " ^ greeting) /> </div>
  }
};

let jsPropsToReason jsProps =>
  make
    message::jsProps##message
    extraGreeting::?(Js.Null_undefined.to_opt jsProps##extraGreeting)
    [||];

let comp = ReasonReact.createJsReactClass ::jsPropsToReason component;

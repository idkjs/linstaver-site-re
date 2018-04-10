[@bs.module] external style : Js.t({..}) = "./about.module.scss";

let component = ReasonReact.statelessComponent("About");

open Utils;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("About Linstaver" |> s) </h1>
      <h2> ("Mission" |> s) </h2>
      <main>
        <p>
          ({js|
                Our mission is....
              |js} |> s)
        </p>
        <p>
          (
            {js|
                Another goal is to ....
              |js} |> s
          )
        </p>
      </main>
      <main />
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
[@bs.module]
external reasonViennaLogo : string = "../assets/partners/reasonvienna.svg";

[@bs.module]
external reactViennaLogo : string = "../assets//partners/reactvienna-logo.svg";

[@bs.module] external style : Js.t({..}) = "./about.module.scss";

let component = ReasonReact.statelessComponent("About");

open Utils;

open Data.Organizer;

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
      <h2> ("Organizers" |> s) </h2>
      <main>
        <p>
          (
            {js|
                We are the organizers of the ReasonVienna community,
                an offspring of ReactVienna. Both organizations are dedicated
                to support the exchange of knowledge and to raise new talents in
                the Austrian web developer community, with a strong focus on Facebook’s
                UI library ReactJS.
             |js}
            |> s
          )
        </p>
      </main>
      <main />
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
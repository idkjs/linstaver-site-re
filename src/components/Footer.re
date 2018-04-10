open Utils;

let component = ReasonReact.statelessComponent("Footer");

[@bs.module] external style : Js.t({..}) = "./footer.module.scss";

/* module Link = Gatsby.Link; */
let make = _children => {
  ...component,
  render: _self =>
    <footer className=style##root>
      <div className="container_centered">
        <Navigation pathName="/" navigationLocation=Footer />
        <section className=style##copyright>
          ({j|

© Linstaver
            |j} |> md)
        </section>
      </div>
    </footer>,
};

let default = Utils.wrapIt(~component, _jsProps => make([||]));
/* let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||])); */
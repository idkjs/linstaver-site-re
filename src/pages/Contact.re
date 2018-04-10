let component = ReasonReact.statelessComponent("Contact");

open Utils;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <section className="thanks grid">
        <h2> (s({j|Address|j})) </h2>
        <p>
          (s({js|Linstaver SA : Rusatiralaan 1 - 1083 Brussels, Belgium |js}))
        </p>
        <p>
          (s("Linstaver Ltd : 68 Lombard Street London EC3V 9LJ, England"))
        </p>
        <p>
          (
            s(
              "Linstaver Ltd, Unit 1411, 14 Floor, Cosco Tower, 183 Queen's Road Central, Hong Kong",
            )
          )
        </p>
        <p>
          <a href="mailto:contact@linstaver.com">
            (s("contact@linstaver.com"))
          </a>
        </p>
      </section>
      <h1> ("Leave us a message" |> s) </h1>
      <section className="thanks grid grid-6col">
        <div className="thanks--grid"> <ContactForm /> </div>
      </section>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
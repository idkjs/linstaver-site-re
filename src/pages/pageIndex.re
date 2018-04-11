let component = ReasonReact.statelessComponent("Home");

open Utils;

module Link = Gatsby.Link;

module ParallaxScroll = Gatsby.ParallaxScroll;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <ParallaxScroll
        from="top-bottom"
        to_="bottom-top"
        props={
          "--header-ty": {
            "from": "100px",
            "to": "-100px",
          },
        }>
        <header className="teaser">
          <section className="container_centered grid grid-6col">
            <h1 className="teaser--logo">
              <div className="logo"> (s("LINSTAVER.COM")) </div>
            </h1>
            /* <img src=Assets.logo alt="Linstaver" className="teaser--image" /> */
            <nav className="teaser--navigation">
              <Navigation pathName="/" />
            </nav>
            <p className="teaser--tagline">
              (
                "Linstaver  is and  Investment, Importer and Exporter Company based in Belgium, UK and HK"
                |> s
              )
            </p>
          </section>
        </header>
      </ParallaxScroll>
      <section className="offering">
        <div className="container_centered grid">
          /* <h2 className="offering--heading"> ("Linstaver" |> s) </h2> */

            <section>
              <p>
                (
                  {js|
### Our Company

Linstaver was conceived as a response to the challenge of combining profitability with social responsibility in a world where success is increasingly measured by financial attainment; this company seeks to utilise profitability from trade and development to promote growth, whilst successfully contributing to social projects.
                  |js}
                  |> md
                )
              </p>
              <p>
                (
                  {js|
### Mission Statement

Profitability achieved through innovative trade and development projects utilising ethical practices while actively supporting charitable initiatives.
                  |js}
                  |> md
                )
              </p>
              <p>
                (
                  {js|
### Services

- **Real Estate**
- **Import/Export**
- **Trading**
- **Investment**
                  |js}
                  |> md
                )
              </p>
            </section>
          </div>
      </section>
    </div>,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
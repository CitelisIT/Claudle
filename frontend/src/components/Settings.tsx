import { Fragment, useContext } from "react";
import { Dialog, Listbox, Switch, Transition } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import { SelectorIcon } from "@heroicons/react/solid";
import { SettingsContext } from "../App";

interface Props {
  settingsOpen: boolean;
  setSettingsOpen: React.Dispatch<React.SetStateAction<boolean>>;
}

const lengths = [4, 5, 6, 7, 8, 9, 10];
const tryNumbers = [4, 5, 6, 7, 8, 9, 10];
const layouts = ["qwerty", "azerty"];

export default function Settings({ settingsOpen, setSettingsOpen }: Props) {
  const settingsContext = useContext(SettingsContext);
  const disabled = settingsContext.gameState === 0 ? false : true;
  return (
    <Transition
      as={Fragment}
      appear
      show={settingsOpen}
      enter="transform origin-top-right transition ease-in-out duration-100"
      enterFrom="scale-0 opacity-0"
      enterTo="scale-100 opacity-100"
      leave="transform origin-top-right transition ease-in-out duration-100"
      leaveFrom="scale-100 opacity-100"
      leaveTo="scale-0 opacity-0"
    >
      <Dialog
        open={settingsOpen}
        onClose={() => setSettingsOpen(false)}
        className="settings"
      >
        <Dialog.Overlay />
        <div className="settings__title">
          <Dialog.Title className="settings__title__text">
            Réglages
          </Dialog.Title>
          <button onClick={() => setSettingsOpen(false)}>
            <XIcon className="settings__title__button" />
          </button>
        </div>
        <hr className="settings__separator" />
        <div className="settings__container">
          <span className="settings__label">Longueur</span>
          <Listbox
            value={settingsContext.size}
            onChange={settingsContext.setSize}
            {...{ disabled }}
          >
            <div className="listbox__wrapper">
              <Listbox.Button className="listbox__button">
                <span className="relative">{settingsContext.size}</span>
                <span className="relative">
                  <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                </span>
              </Listbox.Button>
              <Listbox.Options className="listbox__options">
                {lengths.map((len) => (
                  <Listbox.Option
                    key={len}
                    value={len}
                    disabled={false}
                    className={({ active }) =>
                      active
                        ? "listbox__option--active"
                        : "listbox__option--default"
                    }
                  >
                    {len}
                  </Listbox.Option>
                ))}
              </Listbox.Options>
            </div>
          </Listbox>
          <span className="settings__label">Nombre d'essais</span>
          <Listbox
            value={settingsContext.tries}
            onChange={settingsContext.setTries}
            {...{ disabled }}
          >
            <div className="listbox__wrapper">
              <Listbox.Button className="listbox__button">
                <span className="relative">{settingsContext.tries}</span>
                <span className="relative">
                  <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                </span>
              </Listbox.Button>
              <Listbox.Options className="listbox__options">
                {tryNumbers.map((num) => (
                  <Listbox.Option
                    key={num}
                    value={num}
                    disabled={false}
                    className={({ active }) =>
                      active
                        ? "listbox__option--active"
                        : "listbox__option--default"
                    }
                  >
                    {num}
                  </Listbox.Option>
                ))}
              </Listbox.Options>
            </div>
          </Listbox>
          <span className="settings__label">Mode difficile</span>
          <Switch
            checked={settingsContext.hardMode}
            onChange={settingsContext.setHardMode}
            className={
              settingsContext.hardMode ? "switch--active" : "switch--default"
            }
            {...{ disabled }}
          >
            <span className="sr-only">Activer le mode difficile</span>
            <span
              className={
                settingsContext.hardMode
                  ? "switch__inner--active"
                  : "switch__inner--default"
              }
            />
          </Switch>
          <span className="settings__label">Clavier</span>
          <Listbox
            value={settingsContext.layout}
            onChange={settingsContext.setLayout}
          >
            <div className="listbox__wrapper">
              <Listbox.Button className="listbox__button">
                <span className="relative">{settingsContext.layout}</span>
                <span className="relative">
                  <SelectorIcon className="w-5 h-5" aria-hidden="true" />
                </span>
              </Listbox.Button>
              <Listbox.Options className="listbox__options">
                {layouts.map((layout) => (
                  <Listbox.Option
                    key={layout}
                    value={layout}
                    disabled={false}
                    className={({ active }) =>
                      active
                        ? "listbox__option--active"
                        : "listbox__option--default"
                    }
                  >
                    {layout}
                  </Listbox.Option>
                ))}
              </Listbox.Options>
            </div>
          </Listbox>
        </div>
      </Dialog>
    </Transition>
  );
}
